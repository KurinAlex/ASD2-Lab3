#include <stdlib.h>

#include "Data.h"

#define HP_MAX     10000
#define DAMAGE_MAX 100
#define SKILL_MAX  50

Data::Data()
{
	hp = rand() % HP_MAX + 1;
	damage = rand() % DAMAGE_MAX + 1;
	skill = rand() % SKILL_MAX + 1;
	priority = float(hp / HP_MAX) + float(damage / DAMAGE_MAX) + float(skill / SKILL_MAX);
}