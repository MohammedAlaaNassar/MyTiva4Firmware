/*
 * dio.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"
/*TODO: include the header file that contains register definitions */
#include "../../mcal/mcu_hw.h"

#include "dio.h"

STD_levelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    STD_levelType ret;
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;
    volatile PORT_RegType* PORT_Addr;
    switch (PortId)
          {
          case Dio_Port_A:
              PORT_Addr = &PORTA_REG;
              break;
          case Dio_Port_B:
              PORT_Addr = &PORTB_REG;
              break;
          case Dio_Port_C:
              PORT_Addr = &PORTC_REG;
              break;
          case Dio_Port_D:
              PORT_Addr = &PORTD_REG;
              break;
          case Dio_Port_E:
              PORT_Addr = &PORTE_REG;
              break;
          case Dio_Port_F:
              PORT_Addr = &PORTF_REG;
              break;
          }
    /*TODO: Return the Input Channel Value */
 ret= *( (uint8 *)&(PORT_Addr->GPIODATA)+(1<<ChannelPos+2) );
    return ret;

}

void Dio_WriteChannel(Dio_ChannelType ChannelId, STD_levelType Level)
{
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;
    volatile PORT_RegType* PORT_Addr;
       switch (PortId)
             {
             case Dio_Port_A:
                 PORT_Addr = &PORTA_REG;
                 break;
             case Dio_Port_B:
                 PORT_Addr = &PORTB_REG;
                 break;
             case Dio_Port_C:
                 PORT_Addr = &PORTC_REG;
                 break;
             case Dio_Port_D:
                 PORT_Addr = &PORTD_REG;
                 break;
             case Dio_Port_E:
                 PORT_Addr = &PORTE_REG;
                 break;
             case Dio_Port_F:
                 PORT_Addr = &PORTF_REG;
                 break;
             }

       /*TODO: Write the input value in the corresponding ChannelId */
       if (Level == 1){
   *( (uint8 *)&(PORT_Addr->GPIODATA)+(1<<ChannelPos+2) ) = (uint8)(1<<ChannelPos);
       }
       else
       {
           *( (uint8 *)&(PORT_Addr->GPIODATA)+(1<<ChannelPos+2) ) = ~(uint8)(1<<ChannelPos);
       }
}
uint8 Dio_ReadPort(Dio_PortType PortId )
{
    uint8 ret;
    volatile PORT_RegType* PORT_Addr;
          switch (PortId)
                {
                case Dio_Port_A:
                    PORT_Addr = &PORTA_REG;
                    break;
                case Dio_Port_B:
                    PORT_Addr = &PORTB_REG;
                    break;
                case Dio_Port_C:
                    PORT_Addr = &PORTC_REG;
                    break;
                case Dio_Port_D:
                    PORT_Addr = &PORTD_REG;
                    break;
                case Dio_Port_E:
                    PORT_Addr = &PORTE_REG;
                    break;
                case Dio_Port_F:
                    PORT_Addr = &PORTF_REG;
                    break;
                }

    /*TODO: Return the Port Value*/
          ret = *( (uint8 *)&(PORT_Addr->GPIODATA)+0x3FC );
    return ret;
}
void Dio_WritePort( Dio_PortType PortId, uint8 value)
{
    /*TODO: Write the input value in the corresponding PortId */
    volatile PORT_RegType* PORT_Addr;
        switch (PortId)
              {
              case Dio_Port_A:
                  PORT_Addr = &PORTA_REG;
                  break;
              case Dio_Port_B:
                  PORT_Addr = &PORTB_REG;
                  break;
              case Dio_Port_C:
                  PORT_Addr = &PORTC_REG;
                  break;
              case Dio_Port_D:
                  PORT_Addr = &PORTD_REG;
                  break;
              case Dio_Port_E:
                  PORT_Addr = &PORTE_REG;
                  break;
              case Dio_Port_F:
                  PORT_Addr = &PORTF_REG;
                  break;
              }

    *( (uint8 *)&(PORT_Addr->GPIODATA)+0x3FC )= value;

}
void Dio_FlipChannel( Dio_ChannelType ChannelId)
{

    Dio_PortType PortId = ChannelId / 8;
       Dio_ChannelType ChannelPos = ChannelId % 8;
       volatile PORT_RegType* PORT_Addr;
          switch (PortId)
                {
                case Dio_Port_A:
                    PORT_Addr = &PORTA_REG;
                    break;
                case Dio_Port_B:
                    PORT_Addr = &PORTB_REG;
                    break;
                case Dio_Port_C:
                    PORT_Addr = &PORTC_REG;
                    break;
                case Dio_Port_D:
                    PORT_Addr = &PORTD_REG;
                    break;
                case Dio_Port_E:
                    PORT_Addr = &PORTE_REG;
                    break;
                case Dio_Port_F:
                    PORT_Addr = &PORTF_REG;
                    break;
                }

          /* TODO: toggle the corresponding ChannelId */
     TOGGLE_BIT( *( (uint8 *)&(PORT_Addr->GPIODATA)+(1<<ChannelPos+2) ) , ChannelId  );


}
void Dio_FlipPort(Dio_PortType PortId)
{
    /*TODO: toggle the port value */
    volatile PORT_RegType* PORT_Addr;
            switch (PortId)
                  {
                  case Dio_Port_A:
                      PORT_Addr = &PORTA_REG;
                      break;
                  case Dio_Port_B:
                      PORT_Addr = &PORTB_REG;
                      break;
                  case Dio_Port_C:
                      PORT_Addr = &PORTC_REG;
                      break;
                  case Dio_Port_D:
                      PORT_Addr = &PORTD_REG;
                      break;
                  case Dio_Port_E:
                      PORT_Addr = &PORTE_REG;
                      break;
                  case Dio_Port_F:
                      PORT_Addr = &PORTF_REG;
                      break;
                  }

        *( (uint8 *)&(PORT_Addr->GPIODATA)+0x3FC )^=0xFF ;


}



