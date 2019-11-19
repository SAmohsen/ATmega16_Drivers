/*
 * DIO.c
 *
 *  Created on: Nov 8, 2019
 *      Author: sayed
 */

#include "DIO.h"
#include "DIO_REGS.h"

static uint8 Dio_status = DIO_NOT_INITIALIZED;
static Dio_ConfigChannel *Dio_configuredChannels = NULL_PTR;
static Dio_PortType  *Dio_configuredPorts = NULL_PTR ;


void Dio_Init(const Dio_ConfigType *ConfigPtr) {
	boolean error = FALSE  ;
	/*Error Checking */
	if (NULL_PTR == ConfigPtr)
	{
		/* report Null pointer error */
		error = TRUE ;
	}
	else
	{
		/* no action required */
	}

	if (FALSE == error)
	{
		Dio_configuredChannels = ConfigPtr->Dio_channels ;
		Dio_configuredPorts = ConfigPtr->Dio_ports ;
		Dio_status = DIO_INITIALIZED ;
	}
	else
	{
		/* no action required */

	}

}


/* Function for DIO write Channel API */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
	uint8 *port_ptr = NULL_PTR ;
	boolean error = FALSE ;

	if (DIO_NOT_INITIALIZED == Dio_status)
	{
		/* report DIO not INITIALIZED  error */
		error = TRUE  ;

	}
	else
	{
		/* no action required */
	}
	if (DIO_CONFIGURED_PORTS<=PortId)
	{
		/*report error parameters*/
		error = TRUE ;

	}
	else
	{

	}

	if (FALSE == error)
	{
		/*get port address address*/
		switch (Dio_configuredPorts[PortId])
		{
		case 0: port_ptr = &PORTA_REG ;
		break ;
		case 1: port_ptr = &PORTB_REG ;
		break;
		case 2: port_ptr = &PORTC_REG ;
		break ;
		case 3: port_ptr = &PORTD_REG ;
		break ;
		}

		*port_ptr= Level ;
	}
	else
	{

	}
}

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId) {
	uint8 *pin_ptr = NULL_PTR;
	Dio_PortLevelType portLevel ;
	boolean error = FALSE;

	if (DIO_NOT_INITIALIZED == Dio_status)
	{
		/* report DIO not INITIALIZED  error */
		error = TRUE;
	}
	else
	{
		/* no action required */
	}
	if (DIO_CONFIGURED_PORTS <= PortId)
	{
		/*report error parameters*/
		error = TRUE;
	}
	else
	{

	}

	if (FALSE == error)
	{
		/*get port address address*/
		switch (Dio_configuredPorts[PortId])
		{
		case 0:pin_ptr = &PORTA_REG;
		break;
		case 1:pin_ptr = &PORTB_REG;
		break;
		case 2:pin_ptr = &PORTC_REG;
		break;
		case 3:pin_ptr = &PORTD_REG;
		break;
		}

		portLevel = *pin_ptr ;
		return portLevel ;
	}
	else
	{

	}

}
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level) {
	uint8 *port_ptr = NULL_PTR;
	boolean error = FALSE;

	if (DIO_NOT_INITIALIZED == Dio_status)
	{
		/* report DIO not INITIALIZED  error */
		error = TRUE;

	}
	else
	{
		/* no action required */
	}
	if (DIO_CONFIGURED_CHANNELS <= ChannelId)
	{
		/*report error parameters*/
		error = TRUE;

	}
	else
	{

	}

	if (FALSE == error)
	{
		/*get port address address*/
		switch (Dio_configuredChannels[ChannelId].port_number)
		{
		case 0:port_ptr = &PORTA_REG;
		break;
		case 1:port_ptr = &PORTB_REG;
		break;
		case 2:port_ptr = &PORTC_REG;
		break;
		case 3:port_ptr = &PORTD_REG;
		break;
		}

		if (STD_LOW == Level)
		{
			CLR_BIT(*port_ptr,Dio_configuredChannels[ChannelId].channel_number);
		}
		else if (STD_HIGH == Level)
		{
			SET_BIT(*port_ptr,Dio_configuredChannels[ChannelId].channel_number);
		}
		else
		{

		}
	}
	else
	{

	}

}
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	uint8 *pin_ptr = NULL_PTR;
	Dio_LevelType ChannelLevel;
	boolean error = FALSE;

	if (DIO_NOT_INITIALIZED == Dio_status)
	{
		/* report DIO not INITIALIZED  error */
		error = TRUE;
	}
	else
	{
		/* no action required */
	}
	if (DIO_CONFIGURED_CHANNELS <= ChannelId)
	{
		/*report error parameters*/
		error = TRUE;
	}
	else
	{

	}

	if (FALSE == error) {
		/*get port address address*/
		switch (Dio_configuredChannels[ChannelId].port_number) {
		case 0:pin_ptr = &PORTA_REG;
		break;
		case 1:pin_ptr = &PORTB_REG;
		break;
		case 2:pin_ptr = &PORTC_REG;
		break;
		case 3:pin_ptr = &PORTD_REG;
		break;
		}
		ChannelLevel = READ_BIT(*pin_ptr,Dio_configuredChannels[ChannelId].channel_number);
		return ChannelLevel;

	}
	else
	{

	}
}

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId){

	uint8 *pin_ptr = NULL_PTR;
	uint8 *port_ptr = NULL_PTR;
	Dio_LevelType ChannelLevel;
	boolean error = FALSE;

	if (DIO_NOT_INITIALIZED == Dio_status)
	{
		/* report DIO not INITIALIZED  error */
		error = TRUE;
	}
	else
	{
		/* no action required */
	}
	if (DIO_CONFIGURED_CHANNELS <= ChannelId)
	{
		/*report error parameters*/
		error = TRUE;
	}
	else
	{

	}

	if (FALSE == error)
	{
		/*get port address address*/
		switch (Dio_configuredChannels[ChannelId].port_number)
		{

		case 0:pin_ptr = &PORTA_REG;
			   port_ptr = &PORTA_REG;
		break;

		case 1:pin_ptr = &PORTB_REG;
			   port_ptr = &PORTB_REG;
		break;

		case 2:pin_ptr = &PORTC_REG;
			   port_ptr = &PORTC_REG;
		break;

		case 3:pin_ptr = &PORTD_REG;
			   port_ptr = &PORTD_REG;
		break;
		}
		/* Read the required channel and write the required level */
		if(BIT_IS_SET(*pin_ptr,Dio_configuredChannels[ChannelId].channel_number))
		{
			CLR_BIT(*port_ptr,Dio_configuredChannels[ChannelId].channel_number);
			ChannelLevel = STD_LOW;
		}
		else if (BIT_IS_CLEAR(*pin_ptr,Dio_configuredChannels[ChannelId].channel_number))
		{
			SET_BIT(*port_ptr,Dio_configuredChannels[ChannelId].channel_number);
			ChannelLevel = STD_HIGH;
		}
		else
		{

		}
		return ChannelLevel;
	}
	else
	{

	}

}
