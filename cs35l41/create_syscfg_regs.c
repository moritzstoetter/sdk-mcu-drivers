/**
 * @file create_syscfg.c
 *
 * @brief Tool to create configuration register defaults for the CS35L41 Driver
 *
 * @copyright
 * Copyright (c) Cirrus Logic 2020 All Rights Reserved, http://www.cirrus.com/
 *
 * This code and information are provided 'as-is' without warranty of any
 * kind, either expressed or implied, including but not limited to the
 * implied warranties of merchantability and/or fitness for a particular
 * purpose.
 *
 */
/***********************************************************************************************************************
 * INCLUDES
 **********************************************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include "cs35l41_syscfg_types.h"
#include "cs35l41_spec.h"

/***********************************************************************************************************************
 * LOCAL LITERAL SUBSTITUTIONS
 **********************************************************************************************************************/
#define SYSCFG_REGS_PREFIX           ""
#define SYSCFG_REGS_NAME             "cs35l41_" SYSCFG_REGS_PREFIX "syscfg_regs"
#define SYSCFG_REGS_H_FILENAME SYSCFG_REGS_NAME ".h"
#define SYSCFG_REGS_C_FILENAME SYSCFG_REGS_NAME ".c"

#define CS35L41_CONFIG_REGISTERS_TOTAL                  (32)    ///< Total registers modified during Configure SM

/***********************************************************************************************************************
 * MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * ENUMS, STRUCTS, UNIONS, TYPEDEFS
 **********************************************************************************************************************/
typedef struct
{
    uint32_t address;
    uint32_t mask;
    uint32_t value;
    char *name;
} syscfg_reg_list_entry_t;

/**
 * Registers modified for amplifier configuration.
 *
 * List of registers can be accessed via bitfields (when mapping from driver config/state), or indexed via words
 * (when reading/writing via Control Port).
 *
 * All register types are defined according to the datasheet and specified in cs35l41_spec.h.
 *
 * @warning  The list of registers MUST correspond to the addresses in cs35l41_config_register_addresses.
 *
 * @see cs35l41_config_register_addresses
 */
typedef union
{
    uint32_t words[CS35L41_CONFIG_REGISTERS_TOTAL];

    struct
    {
        cs35l41_intp_amp_ctrl_t intp_amp_ctrl;
        cs35l41_dre_amp_gain_t dre_amp_gain;
        cs35l41_mixer_t asptx1_input;
        cs35l41_mixer_t asptx2_input;
        cs35l41_mixer_t asptx3_input;
        cs35l41_mixer_t asptx4_input;
        cs35l41_mixer_t dsp1rx1_input;
        cs35l41_mixer_t dsp1rx2_input;
        cs35l41_mixer_t dacpcm1_input;
        cs35l41_ccm_global_sample_rate_t ccm_global_sample_rate;
        cs35l41_noise_gate_mixer_ngate_ch1_cfg_t noise_gate_mixer_ngate_ch1_cfg;
        cs35l41_noise_gate_mixer_ngate_ch2_cfg_t noise_gate_mixer_ngate_ch2_cfg;
        cs35l41_ccm_refclk_input_t ccm_refclk_input;
        cs35l41_msm_block_enables_t msm_block_enables;
        cs35l41_msm_block_enables2_t msm_block_enables2;
        cs35l41_dataif_asp_enables1_t dataif_asp_enables1;
        cs35l41_dataif_asp_control2_t dataif_asp_control2;
        cs35l41_dataif_asp_frame_control5_t dataif_asp_frame_control5;
        cs35l41_dataif_asp_frame_control1_t dataif_asp_frame_control1;
        cs35l41_dataif_asp_control3_t dataif_asp_control3;
        cs35l41_dataif_asp_data_control5_t dataif_asp_data_control5;
        cs35l41_dataif_asp_data_control1_t dataif_asp_data_control1;
        uint32_t ccm_fs_mon0;
        cs35l41_dataif_asp_control1_t dataif_asp_control1;
        cs35l41_boost_lbst_slope_t boost_lbst_slope;
        cs35l41_boost_bst_loop_coeff_t boost_bst_loop_coeff;
        cs35l41_boost_bst_ipk_ctl_t boost_bst_ipk_ctl;
        cs35l41_boost_vbst_ctl_1_t boost_vbst_ctl_1;
        cs35l41_boost_vbst_ctl_2_t boost_vbst_ctl_2;
        cs35l41_tempmon_warn_limit_threshold_t tempmon_warn_limit_threshold;
        cs35l41_pwrmgmt_classh_config_t pwrmgmt_classh_config;
        cs35l41_pwrmgmt_wkfet_amp_config_t pwrmgmt_wkfet_amp_config;
    };
} cs35l41_config_registers_t;

/***********************************************************************************************************************
 * LOCAL VARIABLES
 **********************************************************************************************************************/
static cs35l41_syscfg_t cs35l41_syscfg = {{{0}}};
static cs35l41_config_registers_t cleared_regs, set_regs;
static uint32_t updated_regs_total = 0;
static syscfg_reg_list_entry_t syscfg_reg_list[CS35L41_CONFIG_REGISTERS_TOTAL] =
{
    {.address = CS35L41_INTP_AMP_CTRL_REG, .name = "INTP_AMP_CTRL"},
    {.address = CS35L41_DRE_AMP_GAIN_REG, .name = "DRE_AMP_GAIN"},
    {.address = CS35L41_MIXER_ASPTX1_INPUT_REG, .name = "MIXER_ASPTX1_INPUT"},
    {.address = CS35L41_MIXER_ASPTX2_INPUT_REG, .name = "MIXER_ASPTX2_INPUT"},
    {.address = CS35L41_MIXER_ASPTX3_INPUT_REG, .name = "MIXER_ASPTX3_INPUT"},
    {.address = CS35L41_MIXER_ASPTX4_INPUT_REG, .name = "MIXER_ASPTX4_INPUT"},
    {.address = CS35L41_MIXER_DSP1RX1_INPUT_REG, .name = "MIXER_DSP1RX1_INPUT"},
    {.address = CS35L41_MIXER_DSP1RX2_INPUT_REG, .name = "MIXER_DSP1RX2_INPUT"},
    {.address = CS35L41_MIXER_DACPCM1_INPUT_REG, .name = "MIXER_DACPCM1_INPUT"},
    {.address = CCM_GLOBAL_SAMPLE_RATE_REG, .name = "CCM_GLOBAL_SAMPLE_RATE"},
    {.address = NOISE_GATE_MIXER_NGATE_CH1_CFG_REG, .name = "NOISE_GATE_MIXER_NGATE_CH1_CFG"},
    {.address = NOISE_GATE_MIXER_NGATE_CH2_CFG_REG, .name = "NOISE_GATE_MIXER_NGATE_CH2_CFG"},
    {.address = CCM_REFCLK_INPUT_REG, .name = "CCM_REFCLK_INPUT"},
    {.address = MSM_BLOCK_ENABLES_REG, .name = "MSM_BLOCK_ENABLES"},
    {.address = MSM_BLOCK_ENABLES2_REG, .name = "MSM_BLOCK_ENABLES2"},
    {.address = DATAIF_ASP_ENABLES1_REG, .name = "DATAIF_ASP_ENABLES1"},
    {.address = DATAIF_ASP_CONTROL2_REG, .name = "DATAIF_ASP_CONTROL2"},
    {.address = DATAIF_ASP_FRAME_CONTROL5_REG, .name = "DATAIF_ASP_FRAME_CONTROL5"},
    {.address = DATAIF_ASP_FRAME_CONTROL1_REG, .name = "DATAIF_ASP_FRAME_CONTROL1"},
    {.address = DATAIF_ASP_CONTROL3_REG, .name = "DATAIF_ASP_CONTROL3"},
    {.address = DATAIF_ASP_DATA_CONTROL5_REG, .name = "DATAIF_ASP_DATA_CONTROL5"},
    {.address = DATAIF_ASP_DATA_CONTROL1_REG, .name = "DATAIF_ASP_DATA_CONTROL1"},
    {.address = CCM_FS_MON_0_REG, .name = "CCM_FS_MON_0"},
    {.address = DATAIF_ASP_CONTROL1_REG, .name = "DATAIF_ASP_CONTROL1"},
    {.address = BOOST_LBST_SLOPE_REG, .name = "BOOST_LBST_SLOPE"},
    {.address = BOOST_BST_LOOP_COEFF_REG, .name = "BOOST_BST_LOOP_COEFF"},
    {.address = BOOST_BST_IPK_CTL_REG, .name = "BOOST_BST_IPK_CTL"},
    {.address = BOOST_VBST_CTL_1_REG, .name = "BOOST_VBST_CTL_1"},
    {.address = BOOST_VBST_CTL_2_REG, .name = "BOOST_VBST_CTL_2"},
    {.address = TEMPMON_WARN_LIMIT_THRESHOLD_REG, .name = "TEMPMON_WARN_LIMIT_THRESHOLD"},
    {.address = PWRMGMT_CLASSH_CONFIG_REG, .name = "PWRMGMT_CLASSH_CONFIG"},
    {.address = PWRMGMT_WKFET_AMP_CONFIG_REG, .name = "PWRMGMT_WKFET_AMP_CONFIG"},
};

/***********************************************************************************************************************
 * LOCAL FUNCTIONS
 **********************************************************************************************************************/
static void fprint_c_copyright(FILE *fp)
{
    fprintf(fp, "\
/**\n\
 * @file ");
    fprintf(fp, SYSCFG_REGS_C_FILENAME);
    fprintf(fp, "\n\
 *\n\
 * @brief Register values to be applied after CS35L41 Driver boot().\n\
 *\n\
 * @copyright\n\
 * Copyright (c) Cirrus Logic 2020 All Rights Reserved, http://www.cirrus.com/\n\
 *\n\
 * This code and information are provided 'as-is' without warranty of any\n\
 * kind, either expressed or implied, including but not limited to the\n\
 * implied warranties of merchantability and/or fitness for a particular\n\
 * purpose.\n\
 *\n\
 */\n\
");
    return;
}

static void fprint_h_copyright(FILE *fp)
{
    fprintf(fp, "\
/**\n\
 * @file ");
    fprintf(fp, SYSCFG_REGS_H_FILENAME);
    fprintf(fp, "\n\
 *\n\
 * @brief Register values to be applied after CS35L41 Driver boot().\n\
 *\n\
 * @copyright\n\
 * Copyright (c) Cirrus Logic 2020 All Rights Reserved, http://www.cirrus.com/\n\
 *\n\
 * This code and information are provided 'as-is' without warranty of any\n\
 * kind, either expressed or implied, including but not limited to the\n\
 * implied warranties of merchantability and/or fitness for a particular\n\
 * purpose.\n\
 *\n\
 */\n\
");
    return;
}

static void fprintf_include_guard_top(FILE *fp)
{
    fprintf(fp, "\
\n\
#ifndef CS35L41_SYSCFG_REGS_H\n\
#define CS35L41_SYSCFG_REGS_H\n\
\n\
#ifdef __cplusplus\n\
extern \"C\" {\n\
#endif\n\
\n\
");

    return;
}

static void fprintf_include_guard_bottom(FILE *fp)
{
    fprintf(fp, "\
\n\
#ifdef __cplusplus\n\
}\n\
#endif\n\
\n\
#endif // CS35L41_SYSCFG_REGS_H\n\
\n\
");

    return;
}

static void fprint_includes(FILE *fp)
{
    fprintf(fp, "\
/***********************************************************************************************************************\n\
 * INCLUDES\n\
 **********************************************************************************************************************/\n\
");
    return;
}

static void fprint_literals_constants(FILE *fp)
{
    fprintf(fp, "\
/***********************************************************************************************************************\n\
 * LITERALS & CONSTANTS\n\
 **********************************************************************************************************************/\n\
");
    return;
}

static void fprint_globals(FILE *fp)
{
    fprintf(fp, "\
/***********************************************************************************************************************\n\
 * GLOBAL VARIABLES\n\
 **********************************************************************************************************************/\n\
");
    return;
}

static void fprint_typedefs(FILE *fp)
{
    fprintf(fp, "\
/***********************************************************************************************************************\n\
 * ENUMS, STRUCTS, UNIONS, TYPEDEFS\n\
 **********************************************************************************************************************/\n\
");
    return;
}

static void export_header_file(void)
{
    FILE *fp;
    fp = fopen(SYSCFG_REGS_H_FILENAME, "w");
    fprint_h_copyright(fp);
    fprintf_include_guard_top(fp);
    fprint_includes(fp);
    fprintf(fp, "#include \"stdint.h\"\n\n");
    fprint_literals_constants(fp);
    fprintf(fp, "#define CS35L41_SYSCFG_REGS_TOTAL    (%d)\n\n", updated_regs_total);

    uint8_t count = 0;
    for (int i = 0; i < CS35L41_CONFIG_REGISTERS_TOTAL; i++)
    {
        if (syscfg_reg_list[i].mask)
        {
            fprintf(fp,
                    "#define CS35L41_%s_SYSCFG_REGS_INDEX (%d)\n",
                    syscfg_reg_list[i].name,
                    count++);
        }
    }
    fprintf(fp, "\n");

    fprint_typedefs(fp);

    fprintf(fp, "typedef struct\n");
    fprintf(fp, "{\n");
    fprintf(fp, "    uint32_t address;\n");
    fprintf(fp, "    uint32_t mask;\n");
    fprintf(fp, "    uint32_t value;\n");
    fprintf(fp, "} syscfg_reg_t;\n\n");

    fprint_globals(fp);
    fprintf(fp, "extern const syscfg_reg_t %s[];\n", SYSCFG_REGS_NAME);
    fprintf_include_guard_bottom(fp);
    fclose(fp);
    return;
}

static void export_source_file(void)
{
    FILE *fp;

    fp = fopen(SYSCFG_REGS_C_FILENAME, "w");
    fprint_c_copyright(fp);
    fprint_includes(fp);
    fprintf(fp, "#include \"");
    fprintf(fp, SYSCFG_REGS_H_FILENAME);
    fprintf(fp, "\"\n");
    fprintf(fp, "#include \"cs35l41_spec.h\"\n\n");
    fprint_globals(fp);
    fprintf(fp, "const syscfg_reg_t %s[] = \n{\n", SYSCFG_REGS_NAME);

    updated_regs_total = 0;

    for (int i = 0; i < CS35L41_CONFIG_REGISTERS_TOTAL; i++)
    {
        if (syscfg_reg_list[i].mask)
        {
            fprintf(fp,
                    "    {0x%08x, 0x%08x, 0x%08x}, // %s\n",
                    syscfg_reg_list[i].address,
                    syscfg_reg_list[i].mask,
                    syscfg_reg_list[i].value,
                    syscfg_reg_list[i].name);
            updated_regs_total++;
        }
    }
    fprintf(fp, "};\n");
    fclose(fp);
    return;
}

void prepare_reg_sets(void)
{
    // Prepare registers
    for (int i = 0; i < CS35L41_CONFIG_REGISTERS_TOTAL; i++)
    {
        cleared_regs.words[i] = 0x00000000;
        set_regs.words[i] = 0xFFFFFFFF;
        syscfg_reg_list[i].mask = 0x00000000;
        syscfg_reg_list[i].value = 0x00000000;
    }

    return;
}

/**
 * Checks all hardware mixer source selections for a specific source.
 *
 * Implementation of cs35l41_private_functions_t.is_mixer_source_used
 *
 */
static bool cs35l41_is_mixer_source_used(cs35l41_routing_config_t *routing, uint8_t source)
{
    if ((routing->dac_src == source) || \
        (routing->asp_tx1_src == source) || \
        (routing->asp_tx2_src == source) || \
        (routing->asp_tx3_src == source) || \
        (routing->asp_tx4_src == source) || \
        (routing->dsp_rx1_src == source) || \
        (routing->dsp_rx2_src == source))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Apply all driver one-time configurations to corresponding Control Port register/memory addresses
 *
 * Implementation of cs35l41_private_functions_t.apply_configs
 *
 */
static uint32_t apply_syscfg(cs35l41_config_registers_t *regs)
{
    uint32_t ret = -1;
    uint8_t i;
    bool code_found;

    /*
     * apply audio hw configurations
     */
    cs35l41_audio_hw_config_t *hw = &(cs35l41_syscfg.audio_config.hw);
    regs->dataif_asp_control3.asp_dout_hiz_ctrl = hw->dout_hiz_ctrl;

    regs->dataif_asp_control2.asp_bclk_mstr = hw->is_master_mode;
    regs->dataif_asp_control2.asp_fsync_mstr = regs->dataif_asp_control2.asp_bclk_mstr;
    regs->dataif_asp_control2.asp_fsync_inv = hw->fsync_inv;
    regs->dataif_asp_control2.asp_bclk_inv = hw->bclk_inv;

    regs->msm_block_enables2.amp_dre_en = hw->amp_dre_en;

    regs->noise_gate_mixer_ngate_ch1_cfg.aux_ngate_ch1_en = hw->ng_enable;
    regs->noise_gate_mixer_ngate_ch2_cfg.aux_ngate_ch2_en = hw->ng_enable;
    regs->noise_gate_mixer_ngate_ch1_cfg.aux_ngate_ch1_hold = hw->ng_delay;
    regs->noise_gate_mixer_ngate_ch2_cfg.aux_ngate_ch2_hold = hw->ng_delay;
    regs->noise_gate_mixer_ngate_ch1_cfg.aux_ngate_ch1_thr = hw->ng_thld;
    regs->noise_gate_mixer_ngate_ch2_cfg.aux_ngate_ch2_thr = hw->ng_thld;

    regs->dre_amp_gain.amp_gain_pcm = hw->amp_gain_pcm;
    regs->intp_amp_ctrl.amp_ramp_pcm = hw->amp_ramp_pcm;

    /*
     * apply audio clocking configurations
     */
    cs35l41_clock_config_t *clk = &(cs35l41_syscfg.audio_config.clock);

    // apply audio clocking - refclk source
    regs->ccm_refclk_input.pll_refclk_sel = clk->refclk_sel;

    // apply audio clocking - refclk frequency
    code_found = false;
    for (i = 0; i < (sizeof(cs35l41_pll_sysclk)/sizeof(struct cs35l41_register_encoding)); i++)
    {
        if (clk->refclk_freq == cs35l41_pll_sysclk[i].value)
        {
            code_found = true;
            regs->ccm_refclk_input.pll_refclk_freq = cs35l41_pll_sysclk[i].code;
            break;
        }
    }
    if (!code_found)
    {
        ret = -1;
    }

    // apply audio clocking - sclk frequency
    code_found = false;
    for (i = 0; i < (sizeof(cs35l41_sclk_encoding)/sizeof(struct cs35l41_register_encoding)); i++)
    {
        if (clk->sclk == cs35l41_sclk_encoding[i].value)
        {
            code_found = true;
            regs->dataif_asp_control1.asp_bclk_freq = cs35l41_sclk_encoding[i].code;
            break;
        }
    }
    if (!code_found)
    {
        ret = -1;
    }

    // The procedure below is taken from the datasheet, Section 4.13.9
    if (clk->sclk > CS35L41_FS_MON0_BETA)
    {
        regs->ccm_fs_mon0 = 0x00024010;
    }
    else
    {
        uint32_t x = 12 * CS35L41_FS_MON0_BETA / clk->sclk + 4;
        uint32_t y = 20 * CS35L41_FS_MON0_BETA / clk->sclk + 4;
        regs->ccm_fs_mon0 = x + (y * 4096);
    }

    // apply audio clocking - FS configuration
    code_found = false;
    for (i = 0; i < (sizeof(cs35l41_fs_rates)/sizeof(struct cs35l41_register_encoding)); i++)
    {
        if (clk->global_fs == cs35l41_fs_rates[i].value)
        {
            code_found = true;
            regs->ccm_global_sample_rate.global_fs = cs35l41_fs_rates[i].code;
            break;
        }
    }
    if (!code_found)
    {
        ret = -1;
    }

    regs->ccm_refclk_input.pll_refclk_en = 1;

    /*
     * apply audio port configurations
     */
    cs35l41_asp_config_t *asp = &(cs35l41_syscfg.audio_config.asp);
    if (asp->is_i2s)
    {
        regs->dataif_asp_control2.asp_fmt = CS35L41_ASP_CONTROL2_ASP_FMT_I2S;
    }
    else
    {
        regs->dataif_asp_control2.asp_fmt = CS35L41_ASP_CONTROL2_ASP_FMT_DSPA;
    }

    regs->dataif_asp_frame_control5.asp_rx1_slot = asp->rx1_slot;
    regs->dataif_asp_frame_control5.asp_rx2_slot = asp->rx2_slot;
    regs->dataif_asp_frame_control1.asp_tx1_slot = asp->tx1_slot;
    regs->dataif_asp_frame_control1.asp_tx2_slot = asp->tx2_slot;
    regs->dataif_asp_frame_control1.asp_tx3_slot = asp->tx3_slot;
    regs->dataif_asp_frame_control1.asp_tx4_slot = asp->tx4_slot;

    regs->dataif_asp_data_control5.asp_rx_wl = asp->rx_wl;
    regs->dataif_asp_control2.asp_rx_width = asp->rx_width;

    regs->dataif_asp_data_control1.asp_tx_wl = asp->tx_wl;
    regs->dataif_asp_control2.asp_tx_width = asp->tx_width;

    /*
     * apply audio routing configurations
     */
    cs35l41_routing_config_t *routing = &(cs35l41_syscfg.audio_config.routing);
    regs->dacpcm1_input.src = routing->dac_src;
    regs->asptx1_input.src = routing->asp_tx1_src;
    regs->asptx2_input.src = routing->asp_tx2_src;
    regs->asptx3_input.src = routing->asp_tx3_src;
    regs->asptx4_input.src = routing->asp_tx4_src;
    regs->dsp1rx1_input.src = routing->dsp_rx1_src;
    regs->dsp1rx2_input.src = routing->dsp_rx2_src;

    /*
     * apply asp block enable configurations
     */
    regs->dataif_asp_enables1.asp_rx1_en = 0;
    if (cs35l41_is_mixer_source_used(routing, CS35L41_INPUT_SRC_ASPRX1))
    {
        regs->dataif_asp_enables1.asp_rx1_en = 1;
    }

    regs->dataif_asp_enables1.asp_rx2_en = 0;
    if (cs35l41_is_mixer_source_used(routing, CS35L41_INPUT_SRC_ASPRX2))
    {
        regs->dataif_asp_enables1.asp_rx2_en = 1;
    }

    if (routing->asp_tx1_src != CS35L41_INPUT_SRC_DISABLE)
    {
        regs->dataif_asp_enables1.asp_tx1_en = 1;
    }
    if (routing->asp_tx2_src != CS35L41_INPUT_SRC_DISABLE)
    {
        regs->dataif_asp_enables1.asp_tx2_en = 1;
    }
    if (routing->asp_tx3_src != CS35L41_INPUT_SRC_DISABLE)
    {
        regs->dataif_asp_enables1.asp_tx3_en = 1;
    }
    if (routing->asp_tx4_src != CS35L41_INPUT_SRC_DISABLE)
    {
        regs->dataif_asp_enables1.asp_tx4_en = 1;
    }

    /*
     * apply startup volume
     */
    regs->intp_amp_ctrl.amp_vol_pcm = cs35l41_syscfg.audio_config.volume;

    /*
     * apply boost configurations
     */
    cs35l41_amp_config_t *amp = &(cs35l41_syscfg.amp_config);

    uint8_t lbst_code, cbst_code, ipk_code;

    // Get code for Boost Inductor
    switch (amp->boost_inductor_value_nh)
    {
        case 1000:  /* 1.0 uH */
            lbst_code = 0;
            break;

        case 1200:  /* 1.2 uH */
            lbst_code = 1;
            break;

        case 1500:  /* 1.5 uH */
            lbst_code = 2;
            break;

        case 2200:  /* 2.2 uH */
            lbst_code = 3;
            break;

        default:
            ret = -1;
            break;
    }

    // Get code for Boost Capacitor
    switch (amp->boost_capacitor_value_uf)
    {
        case 0 ... 19:
            cbst_code = 0;
            break;

        case 20 ... 50:
            cbst_code = 1;
            break;

        case 51 ... 100:
            cbst_code = 2;
            break;

        case 101 ... 200:
            cbst_code = 3;
            break;

        default:    /* 201 uF and greater */
            cbst_code = 4;
            break;
    }

    // Get Boost Loop Coefficient and LBST Slope based on codes above
    regs->boost_bst_loop_coeff.bst_k1 = cs35l41_bst_k1_table[lbst_code][cbst_code];
    regs->boost_bst_loop_coeff.bst_k2 = cs35l41_bst_k2_table[lbst_code][cbst_code];
    regs->boost_lbst_slope.bst_lbst_val = lbst_code;
    regs->boost_lbst_slope.bst_slope = cs35l41_bst_slope_table[lbst_code];

    // Bounds check the Peak Current configuration
    if ((amp->boost_ipeak_ma < 1600) || (amp->boost_ipeak_ma > 4500))
    {
        ret = -1;
    }
    else
    {
        // Encoding corresponds to values in Datasheet Section 7.11.3
        ipk_code = ((amp->boost_ipeak_ma - 1600) / 50) + 0x10;
    }
    regs->boost_bst_ipk_ctl.bst_ipk = ipk_code;

    regs->boost_vbst_ctl_1.bst_ctl = amp->bst_ctl;
    regs->tempmon_warn_limit_threshold.temp_warn_thld = amp->temp_warn_thld;

    // Only if Class H is enabled, then apply Class H configurations
    if (amp->classh_enable)
    {
        regs->boost_vbst_ctl_2.bst_ctl_sel = amp->bst_ctl_sel;
        regs->boost_vbst_ctl_2.bst_ctl_lim_en = (amp->bst_ctl_lim_en ? 1 : 0);
        regs->pwrmgmt_classh_config.ch_mem_depth = amp->ch_mem_depth;
        regs->pwrmgmt_classh_config.ch_hd_rm = amp->ch_hd_rm;
        regs->pwrmgmt_classh_config.ch_rel_rate = amp->ch_rel_rate;
        if (amp->wkfet_amp_thld != CS35L41_WKFET_AMP_THLD_DISABLED)
        {
            regs->pwrmgmt_wkfet_amp_config.wkfet_amp_dly = amp->wkfet_amp_delay;
            regs->pwrmgmt_wkfet_amp_config.wkfet_amp_thld = amp->wkfet_amp_thld;
        }
    }

    /*
     * apply block enable configurations
     */
    // Always enable the Amplifier section
    regs->msm_block_enables.amp_en = 1;

    // Turn on some blocks by default
    // The DSP needs VMON/IMON data for CSPL
    regs->msm_block_enables.vmon_en = 1;
    regs->msm_block_enables.imon_en = 1;
    // The DSP is using VPMON, CLASSH, and TEMPMON (see cs35l41_post_boot_config[])
    regs->msm_block_enables.vpmon_en = 1;
    regs->msm_block_enables2.classh_en = 1;
    regs->msm_block_enables.tempmon_en = 1;
    regs->msm_block_enables.vbstmon_en = 1;
    regs->msm_block_enables2.wkfet_amp_en = 1;

    regs->msm_block_enables.vbstmon_en = 0;
    if (cs35l41_is_mixer_source_used(routing, CS35L41_INPUT_SRC_VBSTMON))
    {
        regs->msm_block_enables.vbstmon_en = 1;
    }

    regs->msm_block_enables2.wkfet_amp_en = 0;
    if (amp->wkfet_amp_thld != CS35L41_WKFET_AMP_THLD_DISABLED)
    {
        regs->msm_block_enables2.wkfet_amp_en = 1;
    }

    // Always configure as Boost converter enabled.
    regs->msm_block_enables.bst_en = 0x2;

    return ret;
}

static void set_syscfg(void)
{
    cs35l41_syscfg.audio_config.volume = CS35L41_AMP_VOLUME_0DB;

    // Set all defaults
    cs35l41_syscfg.audio_config.hw.amp_dre_en = true;
    cs35l41_syscfg.audio_config.hw.amp_ramp_pcm = 0;
    cs35l41_syscfg.audio_config.hw.bclk_inv = false;
    cs35l41_syscfg.audio_config.hw.dout_hiz_ctrl = 0x2;
    cs35l41_syscfg.audio_config.hw.fsync_inv = false;
    cs35l41_syscfg.audio_config.hw.is_master_mode = false;
    cs35l41_syscfg.audio_config.hw.ng_enable = false;

    cs35l41_syscfg.audio_config.clock.global_fs = 48000;
    cs35l41_syscfg.audio_config.clock.refclk_freq = 3072000;
    cs35l41_syscfg.audio_config.clock.sclk = 3072000;
    cs35l41_syscfg.audio_config.clock.refclk_sel = CS35L41_PLL_REFLCLK_SEL_BCLK;

    cs35l41_syscfg.audio_config.asp.is_i2s = true;
    cs35l41_syscfg.audio_config.asp.rx_width = 32;
    cs35l41_syscfg.audio_config.asp.rx_wl = 24;
    cs35l41_syscfg.audio_config.asp.tx_width = 32;
    cs35l41_syscfg.audio_config.asp.tx_wl = 24;
    cs35l41_syscfg.audio_config.asp.rx1_slot = 0;
    cs35l41_syscfg.audio_config.asp.rx2_slot = 1;
    cs35l41_syscfg.audio_config.asp.tx1_slot = 0;
    cs35l41_syscfg.audio_config.asp.tx2_slot = 1;

    cs35l41_syscfg.audio_config.routing.dac_src = CS35L41_INPUT_SRC_DSP1TX1;
    cs35l41_syscfg.audio_config.routing.asp_tx1_src = CS35L41_INPUT_SRC_VMON;
    cs35l41_syscfg.audio_config.routing.asp_tx2_src = CS35L41_INPUT_SRC_IMON;
    cs35l41_syscfg.audio_config.routing.asp_tx3_src = CS35L41_INPUT_SRC_DISABLE;
    cs35l41_syscfg.audio_config.routing.asp_tx4_src = CS35L41_INPUT_SRC_DISABLE;
    cs35l41_syscfg.audio_config.routing.dsp_rx1_src = CS35L41_INPUT_SRC_ASPRX1;
    cs35l41_syscfg.audio_config.routing.dsp_rx2_src = CS35L41_INPUT_SRC_DISABLE;

    cs35l41_syscfg.amp_config.boost_inductor_value_nh = 1000;   // 1uH on Prince DC
    cs35l41_syscfg.amp_config.boost_capacitor_value_uf = 10;    // 10uF on Prince DC
    cs35l41_syscfg.amp_config.boost_ipeak_ma = 2000;
    cs35l41_syscfg.amp_config.bst_ctl = 0;  // VBST = VP
    cs35l41_syscfg.amp_config.classh_enable = true;
    cs35l41_syscfg.amp_config.bst_ctl_sel = 1;  // Class-H tracking
    cs35l41_syscfg.amp_config.bst_ctl_lim_en = false;
    cs35l41_syscfg.amp_config.ch_mem_depth = 5; // 333.33 - 335.93 us
    cs35l41_syscfg.amp_config.ch_hd_rm = 0xB; // 1.1V
    cs35l41_syscfg.amp_config.ch_rel_rate = 0x4; // 20us
    cs35l41_syscfg.amp_config.wkfet_amp_delay = 0x4; // 100ms
    cs35l41_syscfg.amp_config.wkfet_amp_thld = 0x1; // 0.05V
    cs35l41_syscfg.amp_config.temp_warn_thld = 0x2; // 125C

    return;
}

static void generate_mask_set(void)
{
    for (int i = 0; i < CS35L41_CONFIG_REGISTERS_TOTAL; i++)
    {
        /*
         * If a bitfield is updated in a register, at this point it will be the same value both in the 'cleared_regs'
         * (with values of all 0s) and the 'set_regs' (with values of all 1s).  Below, the mask is generated by the
         * NOT of the XOR of the 'cleared_regs' and 'set_regs'.  The XOR will set all bits to 1 which are different
         * between 'cleared_regs' and 'set_regs' - a bit set for each bit that was NOT changed.  Then the mask that
         * corresponds to updated values is obtained by the NOT of this XOR.
         */
        syscfg_reg_list[i].mask = ~(cleared_regs.words[i] ^ set_regs.words[i]);

        if (syscfg_reg_list[i].mask)
        {
            syscfg_reg_list[i].value = cleared_regs.words[i] & syscfg_reg_list[i].mask;
        }
    }

    return;
}

/***********************************************************************************************************************
 * API FUNCTIONS
 **********************************************************************************************************************/
int main(void)
{
    printf("create_syscfg_regs:\n");

    printf("Creating %s[]...\n", SYSCFG_REGS_NAME);

    prepare_reg_sets();
    set_syscfg();
    apply_syscfg(&cleared_regs);
    apply_syscfg(&set_regs);
    generate_mask_set();

    // Write updated/configured config_reg values to .h/.h file
    printf("Writing to %s and %s...\n", SYSCFG_REGS_H_FILENAME, SYSCFG_REGS_C_FILENAME);

    export_source_file();
    export_header_file();

    printf("Done!\n");

    return 0;
}
