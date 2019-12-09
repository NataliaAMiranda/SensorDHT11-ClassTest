/* 
 * File:   DHT11.h
 * Author: natalia
 *
 * Created on 4 de Dezembro de 2019, 09:05
 */

#ifndef DHT11_H
#define	DHT11_H

//------ Headers ------//
#include <inttypes.h>
#include <util/delay.h>
#include <avr/io.h>
//----------------------//

//----- Auxiliary data -------------------//
#define DHT_ReadInterval			1500
#define __DHT_Delay_Setup			2000
#define DHT_Pin		A, 7

enum DHT_Status_t
{
	DHT_Ok,
	DHT_Error_Humidity,
	DHT_Error_Temperature,
	DHT_Error_Checksum,
	DHT_Error_Timeout
};
//-----------------------------------------//

class DHT11 {
public:
    DHT11();
    DHT11(const DHT11& orig);
    virtual ~DHT11();
    //----- Prototypes---------------------------//
void DHT_Setup();
enum DHT_Status_t DHT_GetStatus();
enum DHT_Status_t DHT_ReadRaw(uint8_t Data[4]);
enum DHT_Status_t DHT_GetTemperature(double *Temperature);
enum DHT_Status_t DHT_GetHumidity(double *Humidity);
enum DHT_Status_t DHT_Read(double *Temperature, double *Humidity);
double DHT_CelsiusToFahrenheit(double Temperature);
double DHT_CelsiusToKelvin(double Temperature);
//-------------------------------------------//
private:

};

#endif	/* DHT11_H */



