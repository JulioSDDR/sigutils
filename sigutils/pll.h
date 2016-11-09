/*

  Copyright (C) 2016 Gonzalo José Carracedo Carballal

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as
  published by the Free Software Foundation, either version 3 of the
  License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this program.  If not, see
  <http://www.gnu.org/licenses/>

*/

#ifndef _SIGUTILS_PLL_H
#define _SIGUTILS_PLL_H

#include "types.h"
#include "iir.h"
#include "ncqo.h"

#define SU_PLL_ORDER_DEFAULT 5

struct sigutils_pll {
  SUFLOAT   alpha;
  SUFLOAT   beta;
  SUFLOAT   lock;
  su_ncqo_t ncqo;
};

typedef struct sigutils_pll su_pll_t;

#define su_pll_INITIALIZER {0., 0., 0., su_ncqo_INITIALIZER}

void su_pll_finalize(su_pll_t *);

SUBOOL su_pll_init(su_pll_t *, SUFLOAT, SUFLOAT);

void su_pll_feed(su_pll_t *, SUFLOAT);

#endif /* _SIGUTILS_PLL_H */
