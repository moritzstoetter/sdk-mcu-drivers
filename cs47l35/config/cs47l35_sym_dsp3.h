
/**
 * @file cs47l35_dsp3_sym.h
 *
 * @brief Master table of known firmware symbols for the CS47L35_DSP3 Driver module
 *
 * @copyright
 * Copyright (c) Cirrus Logic 2021 All Rights Reserved, http://www.cirrus.com/
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * firmware_converter.py SDK version: 4.5.0 - internal
 * Command:  ../../tools/firmware_converter/firmware_converter.py fw_img_v2 cs47l35_dsp3 SC_Voice_Marley_FB_SMSP_dsp3.wmfw --sym-output /home/mstrozek/driver/cs47l35/config/cs47l35_sym_dsp3.h --generic-sym
 *
 *
 */

#ifndef CS47L35_DSP3_SYM_H
#define CS47L35_DSP3_SYM_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 * LITERALS & CONSTANTS
 **********************************************************************************************************************/

/**
 * @defgroup CS47L35_DSP3_ALGORITHMS
 * @brief Defines indicating presence of HALO Core Algorithms
 *
 * @{
 */
#define CS47L35_DSP3_ALGORITHM_SOUNDCLEAR_RT
#define CS47L35_DSP3_ALGORITHM_CYCLE_COUNT
/** @} */

/**
 * @defgroup CS47L35_DSP3_SYM_
 * @brief Single source of truth for firmware symbols known to the driver.
 *
 * @{
 */
// SOUNDCLEAR_RT
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SOUNDCLEAR_RT_XM_STRUCT_T                    (0x1)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_DUMMY                                        (0x2)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SOUNDCLEAR_RT_YM_STRUCT_T                    (0x3)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_WRITEREGID                                   (0x4)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_READREGID                                    (0x5)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCPGA_MICINGAINS4                            (0x6)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCPGA_LINEOUTGAINS4                          (0x7)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCPGA_LINEINGAINS4                           (0x8)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCPGA_SPKROUTGAINS4                          (0x9)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCEC1_ENABLE                                 (0xa)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCEC1_ADAPTEN                                (0xb)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCEC1_REFINEN                                (0xc)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCEC2_ENABLE                                 (0xd)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCEC2_ADAPTEN                                (0xe)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCEC2_REFINEN                                (0xf)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCEC1CONFIG_TAILMS                           (0x10)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCEC1CONFIG_REVERBMS                         (0x11)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCEC1CONFIG_BULKDELAYMSS11                   (0x12)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCEC1CONFIG_ROBUSTNESS                       (0x13)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCEC2CONFIG_TAILMS                           (0x14)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCEC2CONFIG_REVERBMS                         (0x15)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCEC2CONFIG_BULKDELAYMSS11                   (0x16)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCEC2CONFIG_ROBUSTNESS                       (0x17)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVAD_ENABLE                                 (0x18)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVAD_DTDTHRESHS0                            (0x19)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVAD_ADDEN                                  (0x1a)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVAD_SBPCDEN                                (0x1b)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVAD_ENERGYPCDEN                            (0x1c)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVAD_CORRPCDEN                              (0x1d)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVAD_LOWENRMODEEN                           (0x1e)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVAD_LOWSNRMODEEN                           (0x1f)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVAD_TXNOISECLASSEN                         (0x20)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVAD_RXNOISECLASSEN                         (0x21)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVAD_RXTONECLASSEN                          (0x22)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVAD_FILTEREN                               (0x23)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVAD_RAPIDSUPPORTEN                         (0x24)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVAD_TXMINSPEECHTHRESHSQRTS1                (0x25)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVAD_MICSENSITIVITYSQRTS0                   (0x26)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVAD_MICNOISEFLOORSQRTS0                    (0x27)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVAD_TDVADOUTPUT                            (0x28)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVAD_TDVADMINSPEECHTHRESHSQRTS1             (0x29)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCNLP_RXCOMFORTLEVELS0                       (0x2a)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCNLP_TXCOMFORTEN                            (0x2b)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCNLP_RXGAININDTS0                           (0x2c)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCNLP_RXGAININRXSILENCES0                    (0x2d)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCNLP_TXGAININDTS0                           (0x2e)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCNLP_TXGAININRXSTS0                         (0x2f)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCNLP_TXGAININHDS0                           (0x30)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCNLP_TXDDTEN                                (0x31)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCNLP_RXDDTEN                                (0x32)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCNLP_TXRESFACTORS0                          (0x33)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCNLP_TXRESDTDFACTOR                         (0x34)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCNLP_TXRESEN                                (0x35)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCNLP_HALFDUPLEXMS                           (0x36)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCNLP_TXRESGAININECHOS0                      (0x37)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCNLP_TXRESGAININDTS0                        (0x38)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCRXNR_CANCELEN                              (0x39)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCRXNR_CANCELFACTORS0                        (0x3a)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCRXNR_VHIGHNOISEOFFSETFACTORS1              (0x3b)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCRXNR_HIGHNOISEOFFSETFACTORS1               (0x3c)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCRXNR_MEDNOISEOFFSETFACTORS1                (0x3d)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCRXNR_LOWNOISEOFFSETFACTORS1                (0x3e)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCRXNR_VLOWNOISEOFFSETFACTORS1               (0x3f)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCRXNR_NGEN                                  (0x40)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCRXNR_NGSUPPRLEVELS0                        (0x41)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCTXNR_CANCELEN                              (0x42)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCTXNR_CANCELFACTORS0                        (0x43)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCTXNR_VHIGHNOISEOFFSETFACTORS1              (0x44)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCTXNR_HIGHNOISEOFFSETFACTORS1               (0x45)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCTXNR_MEDNOISEOFFSETFACTORS1                (0x46)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCTXNR_LOWNOISEOFFSETFACTORS1                (0x47)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCTXNR_VLOWNOISEOFFSETFACTORS1               (0x48)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCTXNR_NGEN                                  (0x49)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCTXNR_NGSUPPRLEVELS0                        (0x4a)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMM_PROCEN                                  (0x4b)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMM_CANCELEN                                (0x4c)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMM_ADAPTEN                                 (0x4d)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMM_MEQEN                                   (0x4e)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMM_RNFEN                                   (0x4f)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_SPEECHDIRDEG                      (0x50)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_NOISEDIRDEG                       (0x51)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_SPEECHDIRLOWDEG                   (0x52)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_SPEECHDIRHIGHDEG                  (0x53)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_SEMIOFFAXISLOWDEG                 (0x54)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_SEMIOFFAXISHIGHDEG                (0x55)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_OFFAXISLOWDEG                     (0x56)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_OFFAXISHIGHDEG                    (0x57)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_SEMIOFFAXISHIGHSNRTHRESHFACTS2    (0x58)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_SEMIOFFAXISMEDSNRTHRESHFACTS2     (0x59)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_SEMIOFFAXISLOWSNRTHRESHFACTS2     (0x5a)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_OFFAXISHIGHSNRTHRESHFACTS2        (0x5b)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_OFFAXISMEDSNRTHRESHFACTS2         (0x5c)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_OFFAXISLOWSNRTHRESHFACTS2         (0x5d)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_OFFAXISNFDETTH1S0                 (0x5e)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_OFFAXISNFDETTH2S0                 (0x5f)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_NFDETTHS5                         (0x60)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_INTFDETTHS0                       (0x61)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_MICSPACINGMMS9                    (0x62)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_SPATIALTAILMS                     (0x63)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_SPEECHAUTOCALEN                   (0x64)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_NOISEAUTOCALEN                    (0x65)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_SPEECHCALIBGAINS2                 (0x66)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_NOISECALIBGAINS2                  (0x67)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_ANGLEESTEN                        (0x68)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_NOISENULLEN                       (0x69)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_MEQTYPE                           (0x6a)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_MEQINVERTMIC2                     (0x6b)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_SPATIALTHRESHLOWS5                (0x6c)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_SPATIALTHRESHMEDS5                (0x6d)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_SPATIALTHRESHHIGHS5               (0x6e)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_WINDREDUCEEN                      (0x6f)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_WINDREDUCEFACTORS0                (0x70)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_RNFSPATIALPWEN                    (0x71)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_RNFTEMPORALPWEN                   (0x72)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_RNFCCFSMOOTHPARAMS0               (0x73)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_RNFMUMAXS0                        (0x74)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_RNFMUMINS0                        (0x75)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_RNFTAILMS                         (0x76)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_RNFNUMACAUSALSAMP                 (0x77)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMCONFIG_RNFNUMVALIDLAGS                   (0x78)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_TXALCEN                           (0x79)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_RXALCEN                           (0x7a)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_AVCEN                             (0x7b)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_TXALCTARGETLEVELS0                (0x7c)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_RXALCTARGETLEVELS0                (0x7d)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_AVCMINNOISELEVELS0                (0x7e)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_RXCOMPANDERS0                     (0x7f)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_AVCMINGAINS3                      (0x80)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_AVCMAXGAINS3                      (0x81)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_TXALCUPRTARGETLEVELS0             (0x82)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_RXALCUPRTARGETLEVELS0             (0x83)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_TXALCMINGAINS3                    (0x84)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_RXALCMINGAINS3                    (0x85)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_TXALCMAXGAINS3                    (0x86)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_RXALCMAXGAINS3                    (0x87)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_TXAGCEN                           (0x88)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_RXAGCEN                           (0x89)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_TXAGCLWRTARGETLEVELS0             (0x8a)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_RXAGCLWRTARGETLEVELS0             (0x8b)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_TXAGCUPRTARGETLEVELS0             (0x8c)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_RXAGCUPRTARGETLEVELS0             (0x8d)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_TXAGCMINGAINS3                    (0x8e)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_RXAGCMINGAINS3                    (0x8f)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_TXAGCMAXGAINS3                    (0x90)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCDYNAMICS_RXAGCMAXGAINS3                    (0x91)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCRXPEQ_HPFEN                                (0x92)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCRXPEQ_HPFDCBLOCKEN                         (0x93)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCRXPEQ_PEQEN                                (0x94)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCRXPEQ_PEQFILT_PEQFILTEN                    (0x95)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCRXPEQ_PEQFILT_PEQFILTGAINS7                (0x96)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCRXPEQ_PEQFILT_PEQFILTCOEFS1                (0x97)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCRXPEQ_PEQSWBFILT_PEQFILTEN                 (0x98)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCRXPEQ_PEQSWBFILT_PEQGAINS3                 (0x99)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCTXPEQ_HPFEN                                (0x9a)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCTXPEQ_HPFDCBLOCKEN                         (0x9b)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCTXPEQ_PEQEN                                (0x9c)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCTXPEQ_PEQFILT_PEQFILTEN                    (0x9d)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCTXPEQ_PEQFILT_PEQFILTGAINS7                (0x9e)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCTXPEQ_PEQFILT_PEQFILTCOEFS1                (0x9f)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCTXPEQ_PEQSWBFILT_PEQFILTEN                 (0xa0)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCTXPEQ_PEQSWBFILT_PEQGAINS3                 (0xa1)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCSPARE_PARAM                                (0xa2)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCPSR_ENABLE                                 (0xa3)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCPSR_ICONVGAINS4                            (0xa4)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCPSR_VCONVGAINS4                            (0xa5)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCPSR_COILRESISTANCES4                       (0xa6)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCPSR_COILINDUCTANCES0                       (0xa7)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_ENABLE                                 (0xa8)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_BANDENABLE0                            (0xa9)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_BANDENABLE1                            (0xaa)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_BANDENABLE2                            (0xab)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_BANDENABLE3                            (0xac)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_BANDENABLE4                            (0xad)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_LOOKAHEADS3                            (0xae)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC0THRESHOLDS11                       (0xaf)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC0RATIOS11                           (0xb0)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC0ATTACKS3                           (0xb1)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC0RELEASES3                          (0xb2)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC0KNEES11                            (0xb3)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC0MAKEUPS11                          (0xb4)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC1THRESHOLDS11                       (0xb5)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC1RATIOS11                           (0xb6)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC1ATTACKS3                           (0xb7)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC1RELEASES3                          (0xb8)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC1KNEES11                            (0xb9)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC1MAKEUPS11                          (0xba)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC2THRESHOLDS11                       (0xbb)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC2RATIOS11                           (0xbc)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC2ATTACKS3                           (0xbd)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC2RELEASES3                          (0xbe)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC2KNEES11                            (0xbf)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC2MAKEUPS11                          (0xc0)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC3THRESHOLDS11                       (0xc1)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC3RATIOS11                           (0xc2)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC3ATTACKS3                           (0xc3)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC3RELEASES3                          (0xc4)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC3KNEES11                            (0xc5)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC3MAKEUPS11                          (0xc6)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC4THRESHOLDS11                       (0xc7)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC4RATIOS11                           (0xc8)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC4ATTACKS3                           (0xc9)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC4RELEASES3                          (0xca)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC4KNEES11                            (0xcb)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBC_DRC4MAKEUPS11                          (0xcc)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBCFILTER_TAPSSTG1AP1S1                    (0xcd)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBCFILTER_TAPSSTG1AP2S1                    (0xce)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBCFILTER_TAPSSTG2AP1S1                    (0xcf)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBCFILTER_TAPSSTG2AP2S1                    (0xd0)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBCFILTER_TAPSSTG3AP1S1                    (0xd1)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBCFILTER_TAPSSTG3AP2S1                    (0xd2)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBCFILTER_TAPSSTG4AP1S1                    (0xd3)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMBCFILTER_TAPSSTG4AP2S1                    (0xd4)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVERINFO_PRODUCTID                          (0xd5)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVERINFO_VERNUMBER                          (0xd6)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVERINFO_MAJORREV                           (0xd7)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVERINFO_MINORREV                           (0xd8)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVERINFO_BUILDIDA                           (0xd9)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVERINFO_BUILDIDB                           (0xda)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVERINFO_BUILDIDC                           (0xdb)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVERINFO_BUILDIDD                           (0xdc)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCVERINFO_CUSTOMID                           (0xdd)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCSTATISTICS_NOISELEVEL                      (0xde)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCSTATUS_FLENGTH                             (0xdf)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCSTATUS_BWMODE                              (0xe0)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCSTATUS_NUMMICS                             (0xe1)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCSTATUS_NUMSPARES                           (0xe2)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCSTATUS_MAXAECTAILMS                        (0xe3)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCSTATUS_MAXAECBULKDELAYMSS11                (0xe4)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCSTATUS_MAXSPATIALFILTERTAILMS              (0xe5)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMEST_SPEECHCALIBGAINS2                    (0xe6)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SCMMEST_NOISECALIBGAINS2                     (0xe7)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPPROCMODE_MODE                             (0xe8)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_TRPGA_TXGAINS4                               (0xe9)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_TRPGA_RXGAINS4                               (0xea)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_TRMODE_MODE                                  (0xeb)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPRXPEQPARAMS_PEQFILTF0S9                   (0xec)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPRXPEQPARAMS_PEQFILTDBGAINS14              (0xed)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPRXPEQPARAMS_PEQFILTSS12                   (0xee)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPTXPEQPARAMS_PEQFILTF0S9                   (0xef)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPTXPEQPARAMS_PEQFILTDBGAINS14              (0xf0)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPTXPEQPARAMS_PEQFILTSS12                   (0xf1)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPVERINFO_APPVERNUMBER                      (0xf2)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPVERINFO_APPMAJORREV                       (0xf3)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPVERINFO_APPMINORREV                       (0xf4)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPBWSTATUS_MODE                             (0xf5)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_FRAMECNTR                        (0xf6)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_TESTPOINT0                       (0xf7)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_TESTPOINT1                       (0xf8)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_TESTPOINT2                       (0xf9)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_TESTPOINT3                       (0xfa)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_MAXCLKCNTMSWRD                   (0xfb)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_MAXCLKCNTLSWRD                   (0xfc)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_ENERGYNUMFRAMES                  (0xfd)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_LINEINABSMAX                     (0xfe)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_LINEINCLIPCNT                    (0xff)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_LINEINENERGYFRACTBITS            (0x100)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_LINEINENERGYMSWRD                (0x101)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_LINEINENERGYLSWRD                (0x102)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_SPKROUTABSMAX                    (0x103)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_SPKROUTCLIPCNT                   (0x104)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_SPKROUTENERGYFRACTBITS           (0x105)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_SPKROUTENERGYMSWRD               (0x106)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_SPKROUTENERGYLSWRD               (0x107)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_LINEOUTABSMAX                    (0x108)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_LINEOUTCLIPCNT                   (0x109)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_LINEOUTENERGYFRACTBITS           (0x10a)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_LINEOUTENERGYMSWRD               (0x10b)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_LINEOUTENERGYLSWRD               (0x10c)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_MICINABSMAX                      (0x10d)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_MICINCLIPCNT                     (0x10e)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_MICINENERGYFRACTBITS             (0x10f)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_MICINENERGYMSWRD                 (0x110)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_MICINENERGYLSWRD                 (0x111)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_MIC1INABSMAX                     (0x112)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_MIC1INCLIPCNT                    (0x113)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_MIC1INENERGYFRACTBITS            (0x114)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_MIC1INENERGYMSWRD                (0x115)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_APPCNRSTATS_MIC1INENERGYLSWRD                (0x116)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_TRBWSTATUS_FLENGTH                           (0x117)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_TRBWSTATUS_BWMODE                            (0x118)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_TRBWSTATUS_NUMMICS                           (0x119)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_TRMSRDTXDLY_MEASUREDDLYMSS11                 (0x11a)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SYSTGTINFO_FLAGSMSW                          (0x11b)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SYSTGTINFO_FLAGSLSW                          (0x11c)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SYSTGTINFO_MAXCLOCKMSW                       (0x11d)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SYSTGTINFO_MAXCLOCKLSW                       (0x11e)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SYSTGTINFO_MICINCODECNUMSTEPS                (0x11f)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SYSTGTINFO_MICINCODECMINGAINS6               (0x120)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SYSTGTINFO_MICINCODECSTEPGAINS6              (0x121)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SYSTGTINFO_LINEINCODECNUMSTEPS               (0x122)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SYSTGTINFO_LINEINCODECMINGAINS6              (0x123)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SYSTGTINFO_LINEINCODECSTEPGAINS6             (0x124)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SYSTGTINFO_LINEOUTCODECNUMSTEPS              (0x125)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SYSTGTINFO_LINEOUTCODECMINGAINS6             (0x126)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SYSTGTINFO_LINEOUTCODECSTEPGAINS6            (0x127)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SYSTGTINFO_SPKROUTCODECNUMSTEPS              (0x128)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SYSTGTINFO_SPKROUTCODECMINGAINS6             (0x129)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SYSTGTINFO_SPKROUTCODECSTEPGAINS6            (0x12a)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SYSTGTINFO_MAXALLOWEDCMDSIZE                 (0x12b)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SYSTGTINFO_MAXMICSALLOWED                    (0x12c)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SYSTGTINFO_MICINCODECPREAMPGAINS6            (0x12d)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SYSTGTINFO_TGTTYPEID                         (0x12e)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SYSTGTINFO_MAXLOGXFERSIZE                    (0x12f)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_ISCRSVDSTATS_SCRSVDSTATS                     (0x130)
#define CS47L35_DSP3_SYM_SOUNDCLEAR_RT_SOUNDCLEAR_RT_ZM_STRUCT_T                    (0x131)
// CYCLE_COUNT
#define CS47L35_DSP3_SYM_CYCLE_COUNT_CYCLE_COUNT_XM_STRUCT_T                        (0x133)
#define CS47L35_DSP3_SYM_CYCLE_COUNT_ENABLE                                         (0x134)
#define CS47L35_DSP3_SYM_CYCLE_COUNT_MIPS_AVAIL                                     (0x135)
#define CS47L35_DSP3_SYM_CYCLE_COUNT_MIN_MIPS_AVAIL                                 (0x136)
#define CS47L35_DSP3_SYM_CYCLE_COUNT_UPDATE_MIN_MIPS_AVAIL                          (0x137)

/** @} */

/**********************************************************************************************************************/
#ifdef __cplusplus
}
#endif

#endif // CS47L35_DSP3_SYM_H
