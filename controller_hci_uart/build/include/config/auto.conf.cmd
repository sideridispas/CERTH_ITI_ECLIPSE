deps_config := \
	/home/sideridis/esp/esp-idf/components/app_trace/Kconfig \
	/home/sideridis/esp/esp-idf/components/aws_iot/Kconfig \
	/home/sideridis/esp/esp-idf/components/bt/Kconfig \
	/home/sideridis/esp/esp-idf/components/esp32/Kconfig \
	/home/sideridis/esp/esp-idf/components/ethernet/Kconfig \
	/home/sideridis/esp/esp-idf/components/fatfs/Kconfig \
	/home/sideridis/esp/esp-idf/components/freertos/Kconfig \
	/home/sideridis/esp/esp-idf/components/heap/Kconfig \
	/home/sideridis/esp/esp-idf/components/log/Kconfig \
	/home/sideridis/esp/esp-idf/components/lwip/Kconfig \
	/home/sideridis/esp/esp-idf/components/mbedtls/Kconfig \
	/home/sideridis/esp/esp-idf/components/openssl/Kconfig \
	/home/sideridis/esp/esp-idf/components/pthread/Kconfig \
	/home/sideridis/esp/esp-idf/components/spi_flash/Kconfig \
	/home/sideridis/esp/esp-idf/components/spiffs/Kconfig \
	/home/sideridis/esp/esp-idf/components/tcpip_adapter/Kconfig \
	/home/sideridis/esp/esp-idf/components/wear_levelling/Kconfig \
	/home/sideridis/esp/esp-idf/components/bootloader/Kconfig.projbuild \
	/home/sideridis/esp/esp-idf/components/esptool_py/Kconfig.projbuild \
	/home/sideridis/esp/esp-idf/components/partition_table/Kconfig.projbuild \
	/home/sideridis/esp/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
