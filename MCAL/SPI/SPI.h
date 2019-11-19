/*
 * SPI.h
 *
 *  Created on: Nov 13, 2019
 *      Author: sayed
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

#include "../../std_types.h"
#include "../../micro_config.h"
#include "../../common_marcos.h"

typedef enum {
Lsb_first,
Msb_first,
}Spi_DataOrderType;

typedef enum {
	Spi_Rissing_Edge,
	Spi_Falling_Edge,
} Spi_ClockPloarityType;

typedef enum {
	SCK_Prescale_4,
	SCK_Prescale_16,
	SCK_Prescale_128,
	SCK_Prescale_2,
	SCK_Prescale_8,
	SCK_Prescale_32,
	SCK_Prescale_64,

}Spi_PrescaleType;


typedef enum {
	Spi_normal_speed,
	Spi_double_speed
}Spi_TransmissionSpeedModeType;

typedef enum{
	Spi_master,
	Spi_slave
}Spi_NodeModeType;
typedef struct {
	Spi_DataOrderType data_order;
	Spi_ClockPloarityType clock ;
	Spi_PrescaleType prescale ;
	Spi_TransmissionSpeedModeType speed;
	Spi_NodeModeType mode ;
}Spi_configChannel;
#endif /* MCAL_SPI_SPI_H_ */
