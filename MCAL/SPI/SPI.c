/*
 * SPI.c
 *
 *  Created on: Nov 13, 2019
 *      Author: sayed
 */

#include "SPI.h"
void Spi_Init(Spi_configChannel *Config_ptr){
	/*Enable Spi*/
	//SET_BIT(SPCR,SPE);

	switch (Config_ptr->data_order) {
	case Lsb_first:
		SET_BIT(SPCR, DORD);
		break;
	case Msb_first:
		CLR_BIT(SPCR, DORD);
		break;
	}

	switch (Config_ptr->mode) {
	case Spi_master:
		//SET_BIT(SPCR, MSTR);
		SPCR |= (1<<SPE) | (1<<MSTR);
		break;
	case Spi_slave:
		//CLR_BIT(SPCR, MSTR);
		SPCR |= (1<<SPE) ;
		break;
	}

	switch (Config_ptr->clock) {
	case Spi_Rissing_Edge:
		CLR_BIT(SPCR, CPOL);
		break;
	case Spi_Falling_Edge:
		SET_BIT(SPCR, CPOL);
		break;
	}

	switch (Config_ptr->speed)
	{
	case Spi_normal_speed:CLR_BIT(SPSR,SPI2X);
	break;
	case Spi_double_speed:SET_BIT(SPSR,SPI2X);
	break;
	}

	if (Config_ptr->speed == Spi_normal_speed) {
		switch (Config_ptr->prescale) {
		case SCK_Prescale_4:
			CLR_BIT(SPCR, SPR0);
			CLR_BIT(SPCR, SPR1);

			break;
		case SCK_Prescale_16:
			SET_BIT(SPCR, SPR0);
			CLR_BIT(SPCR, SPR1);
			break;

		case SCK_Prescale_128:
			SET_BIT(SPCR, SPR1);
			CLR_BIT(SPCR, SPR0);
			break;

		case SCK_Prescale_64:
			SET_BIT(SPCR, SPR0);
			SET_BIT(SPCR, SPR1);
			break;

		}
	}

	else if (Config_ptr->speed == Spi_double_speed)
	{
		switch (Config_ptr->prescale) {
		case SCK_Prescale_2:
			CLR_BIT(SPCR, SPR0);
			CLR_BIT(SPCR, SPR1);
			break;

		case SCK_Prescale_8:
			SET_BIT(SPCR, SPR0);
			CLR_BIT(SPCR, SPR1);
			break;

		case SCK_Prescale_32:
			SET_BIT(SPCR, SPR1);
			CLR_BIT(SPCR, SPR0);
			break;

		case SCK_Prescale_64:
			SET_BIT(SPCR, SPR0);
			SET_BIT(SPCR, SPR1);
			break;

		}
	}
	else
	{

	}


}
void Spi_SendU8Data(uint8 data) {
	SPDR = data;
	while (BIT_IS_CLEAR(SPSR, SPIF));
}
uint8 Spi_RecieveU8Data() {
	while (BIT_IS_CLEAR(SPSR, SPIF));
	return SPDR ;
}
void Spi_SendString(uint8 *str){
	uint8 itr = 0 ;
	while (str[itr]!='\0'){
		Spi_SendU8Data(str[itr]);
		itr++;
	}
}
void Spi_RecieveString(uint8 *str){
	uint8 itr = 0 ;
	while (str[itr]!='#'){
		str[itr] = Spi_RecieveU8Data();
		itr++;
	}
	str[itr]='\0';
}

