/*
 * DIO_PBcfg.c
 *
 *  Created on: Nov 8, 2019
 *      Author: sayed
 */

#include "../../std_types.h"
#include "DIO.h"
#include "DIO_cfg.h"


/*post build configurations */
const Dio_ConfigType DIO_configuration = {
		.Dio_ports[DioConf_PORT2_PORT_ID_INDEX]=DioConf_PORT2_PORT_NUM ,
		.Dio_ports[DioConf_PORT1_PORT_ID_INDEX]=DioConf_PORT1_PORT_NUM ,
		.Dio_channels[DioConf_LED1_PORT_ID_INDEX].channel_number=DioConf_LED1_channel_NUMBER,
		.Dio_channels[DioConf_LED1_PORT_ID_INDEX].port_number=DioConf_LED1_PORT_NUMBER,
		.Dio_channels[DioConf_LED2_PORT_ID_INDEX].channel_number=DioConf_LED2_channel_NUMBER,
		.Dio_channels[DioConf_LED2_PORT_ID_INDEX].port_number=DioConf_LED2_PORT_NUMBER,



};
