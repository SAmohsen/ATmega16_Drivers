/*
 * DIO_cfg.h
 *
 *  Created on: Nov 8, 2019
 *      Author: sayed
 */

#ifndef DIO_CFG_H_
#define DIO_CFG_H_



#include "../../std_types.h"



/*
 *
 *
 *configure number of channels and  number of ports
 *
 */

#define DIO_CONFIGURED_CHANNELS (2U)
#define DIO_CONFIGURED_PORTS (2U)


/*SET your configurations */

/* Channel Index in the array of structures in Dio_PBcfg.c */
#define DioConf_PORT1_PORT_ID_INDEX        (uint8)0x00
#define DioConf_PORT2_PORT_ID_INDEX        (uint8)0x01

#define DioConf_PORT1_PORT_NUM                (Dio_PortType)0 /* PORTA */
#define DioConf_PORT2_PORT_NUM                (Dio_PortType)3 /* PORTD */

#define DioConf_LED1_PORT_ID_INDEX        (uint8)0x00
#define DioConf_LED2_PORT_ID_INDEX        (uint8)0x01

#define DioConf_LED1_channel_NUMBER        (uint8)5
#define DioConf_LED2_channel_NUMBER        (uint8)5


#define DioConf_LED1_PORT_NUMBER        (uint8)2
#define DioConf_LED2_PORT_NUMBER        (uint8)1

#endif /* DIO_CFG_H_ */
