#!/bin/bash
#source /opt/esp/entrypoint.sh
#
if [ ! -f sdkconfig ];then
    idf.py menuconfig
fi
idf.py build
python -m esptool --chip esp32s3 merge_bin -o allinone.bin --flash_mode dio --flash_size 8MB --flash_freq 80m 0x0 build/bootloader/bootloader.bin 0x8000 build/partition_table/partition-table.bin 0xd000 build/ota_data_initial.bin 0x10000 build/srmodels/srmodels.bin 0x100000 build/xiaozhi.bin
