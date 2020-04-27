/*
 * bitcontrol.h
 *
 * Created: 16.04.2020 13:55:34
 * Author:  Denis Dengler, Maximilan Kürschner, David Schader
 * Version: 0.0.1
 * Description: Definition of bit control macros
 */ 

#ifndef BITCONTROL_H
#define BITCONTROL_H

/* constants and defines */ 
#define SET_BIT(PORT, BIT) PORT |= (1 << BIT);
#define CLEAR_BIT(PORT, BIT) PORT &= ~(1 << BIT);
#define TOGGLE_BIT(PORT, BIT) PORT ^= (1 << BIT);

#endif /* BITCONTROL_H */