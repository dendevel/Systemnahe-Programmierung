#ifndef BITCONTROL_H
#define BITCONTROL_H

#define SET_BIT(PORT, BIT) PORT|=(1<<BIT);
#define CLEAR_BIT(PORT, BIT) PORT&=~(1<<BIT);
#define TOGGLE_BIT(PORT, BIT) PORT^=(1<<BIT);

#endif /* BITCONTROL_H */