# This same fix exists upstream in sunx64.inc but its not included 
# for 32-bit like the olinuxino-a20-emmc. Experiencing wic compile 
# error where dtb cant be found after adding the 'allwinner' prefix
# to KERNEL_DEVICETREE.
#
#  arm dbts are under <vendor>/dts but is deployed under DEPLOYDIR 
do_fix_device_tree_location() {

    for kdt in ${KERNEL_DEVICETREE}
    do
        local dbt_dir=$(dirname ${kdt})
        if [ "." != "${dbt_dir}" ] ; then
            local dbt=$(basename ${kdt})
            local dst=${DEPLOY_DIR_IMAGE}/${dbt_dir}/${dbt}
            if [ ! -f ${dst} ] ; then
                mkdir -p ${DEPLOY_DIR_IMAGE}/$dbt_dir
                ln -s ${DEPLOY_DIR_IMAGE}/${dbt} ${dst}
            fi
        fi
    done
}

addtask do_fix_device_tree_location after do_write_wks_template before do_image_wic
