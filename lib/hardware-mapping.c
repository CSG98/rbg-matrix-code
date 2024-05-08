/* -*- mode: c; c-basic-offset: 2; indent-tabs-mode: nil; -*-
 * Copyright (C) 2013, 2016 Henner Zeller <h.zeller@acm.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation version 2.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http: *gnu.org/licenses/gpl-2.0.txt>
 */

/*
 * We do this in plain C so that we can use designated initializers.
 */
#include "hardware-mapping.h"

#define GPIO_BIT(b) ((uint64_t)1<<(b))

struct HardwareMapping matrix_hardware_mappings[] = {
  /*
   * The regular hardware mapping described in the wiring.md and used
   * by the adapter PCBs.
   */
  {
    .name          = "regular",

    .output_enable = GPIO_BIT(18),
    .clock         = GPIO_BIT(17),
    .strobe        = GPIO_BIT(4),

    /* Address lines */
    .a             = GPIO_BIT(22),
    .b             = GPIO_BIT(23),
    .c             = GPIO_BIT(24),
    .d             = GPIO_BIT(25),
    .e             = GPIO_BIT(15),  /* RxD kept free unless 1:64 */

    /* Parallel chain 0, RGB for both sub-panels */
    .p0_r1         = GPIO_BIT(11),  /* masks: SPI0_SCKL  */
    .p0_g1         = GPIO_BIT(27),  /* Not on RPi1, Rev1; use "regular-pi1" instead */
    .p0_b1         = GPIO_BIT(7),   /* masks: SPI0_CE1   */
    .p0_r2         = GPIO_BIT(8),   /* masks: SPI0_CE0   */
    .p0_g2         = GPIO_BIT(9),   /* masks: SPI0_MISO  */
    .p0_b2         = GPIO_BIT(10),  /* masks: SPI0_MOSI  */

    
    /* No more chains - there are not enough GPIO */
  },


  {0}
};
