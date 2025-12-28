/*
 * Copyright (c) 2024 Nordic Semiconductor ASA
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file Common power.h include for Nordic Haltium SoCs.
 */

#ifndef _ZEPHYR_SOC_ARM_NORDIC_NRF_HALTIUM_POWER_H_
#define _ZEPHYR_SOC_ARM_NORDIC_NRF_HALTIUM_POWER_H_

#if defined(CONFIG_SOC_NRF54H20_CPUAPP) || defined(CONFIG_SOC_NRF9280_CPUAPP)
#define RAMBLOCK_CONTROL_BIT_ICACHE MEMCONF_POWER_CONTROL_MEM1_Pos
#define RAMBLOCK_CONTROL_BIT_DCACHE MEMCONF_POWER_CONTROL_MEM2_Pos
#define RAMBLOCK_POWER_ID           0
#define RAMBLOCK_CONTROL_OFF        0
#define RAMBLOCK_RET_MASK           (MEMCONF_POWER_RET_MEM0_Msk)
#define RAMBLOCK_RET_BIT_ICACHE     MEMCONF_POWER_RET_MEM1_Pos
#define RAMBLOCK_RET_BIT_DCACHE     MEMCONF_POWER_RET_MEM2_Pos
#elif defined(CONFIG_SOC_NRF54H20_CPURAD) || defined(CONFIG_SOC_NRF9280_CPURAD)
#define RAMBLOCK_CONTROL_BIT_ICACHE MEMCONF_POWER_CONTROL_MEM6_Pos
#define RAMBLOCK_CONTROL_BIT_DCACHE MEMCONF_POWER_CONTROL_MEM7_Pos
#define RAMBLOCK_POWER_ID           0
#define RAMBLOCK_CONTROL_OFF        0
#define RAMBLOCK_RET_MASK                                                                          \
	(MEMCONF_POWER_RET_MEM0_Msk | MEMCONF_POWER_RET_MEM1_Msk | MEMCONF_POWER_RET_MEM2_Msk |    \
	 MEMCONF_POWER_RET_MEM3_Msk | MEMCONF_POWER_RET_MEM4_Msk | MEMCONF_POWER_RET_MEM5_Msk |    \
	 MEMCONF_POWER_RET_MEM8_Msk)
#define RAMBLOCK_RET2_MASK                                                                         \
	(MEMCONF_POWER_RET2_MEM0_Msk | MEMCONF_POWER_RET2_MEM1_Msk | MEMCONF_POWER_RET2_MEM2_Msk | \
	 MEMCONF_POWER_RET2_MEM3_Msk | MEMCONF_POWER_RET2_MEM4_Msk | MEMCONF_POWER_RET2_MEM5_Msk | \
	 MEMCONF_POWER_RET2_MEM8_Msk)
#define RAMBLOCK_RET_BIT_ICACHE  MEMCONF_POWER_RET_MEM6_Pos
#define RAMBLOCK_RET_BIT_DCACHE  MEMCONF_POWER_RET_MEM7_Pos
#define RAMBLOCK_RET2_BIT_ICACHE MEMCONF_POWER_RET2_MEM6_Pos
#define RAMBLOCK_RET2_BIT_DCACHE MEMCONF_POWER_RET2_MEM7_Pos
#endif

/**
 * @brief * @brief Power domain early init.
 *
 */
void power_domain_init(void);

/**
 * @brief Perform a power off.
 *
 * This function performs a power off of the core.
 */
void nrf_poweroff(void);

/**
 * @brief Power up and enable instruction and data cache.
 */
void nrf_power_up_cache(void);

#endif /* _ZEPHYR_SOC_ARM_NORDIC_NRF_HALTIUM_POWER_H_ */
