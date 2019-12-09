/* 
 * File:   GPIO.cpp
 * Author: natalia
 * 
 * Created on 29 de Setembro de 2019, 22:43
 */

#include <avr/io.h>
#include "GPIO.h"

GPIO::GPIO(uint8_t id, PortDirection_t dir):
_id(id)
{
	switch (_id) {
	case 0:
	case 1:
		_bit = (1 << id);
		_pin = &PINE;
		_ddr = &DDRE;
		_port = &PORTE;
		break;
	case 2:
	case 3:
		_bit = id + 2;
        _pin = &PINE;
		_ddr = &DDRE;
		_port = &PORTE;
		break;

	case 4:
		_bit = DDG5;
		_pin = &PING;
		_ddr = &DDRG;
		_port = &PORTG;
		break;

	case 5:
		_bit =  DDE3;
		_pin = &PINE;
		_ddr = &DDRE;
		_port = &PORTE;
		break;

	case 6:
	case 7:
	case 8:
	case 9:
		_bit = id - 3;
		_pin = &PINH;
		_ddr = &DDRH;
		_port = &PORTH;
		break;

	case 10:
	case 11:
	case 12:
	case 13:
		_bit = id - 6;
        _pin = &PINB;
        _ddr = &DDRB;
        _port = &PORTB;
		break;

	}
	if (dir)
        //Atribuição por OR
		*_ddr |= _bit;
	else
        //Atribuição por AND
		*_ddr &= ~_bit;
}

GPIO::~GPIO() {}

bool GPIO::get() {
    //quando tiver entrada, fazer leitura direto do ponteiro _pin
    return (bool) _pin & _bit;
}

void GPIO::set(bool val) {
	//escrever 0 ou 1 usando ponteiro _port
    if (val)
		*_port |= _bit;
	else
		*_port &= ~_bit;
}

void GPIO::clear() {
	this->set(0);
}

void GPIO::toggle() {
    //inverte o valor da porta Exemplo: inverter PB7 -> por 1 no PINB7
    *_pin = _bit;
}
