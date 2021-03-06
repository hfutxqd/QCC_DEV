#ifndef __TEST_H__
#define __TEST_H__

/*! file  @brief Functions to enter BlueCore test modes */
#define FIRST_PCM_IF 0

#if TRAPSET_TEST

/**
 *  \brief Internal function. Don't call this function directly. Don't rely on this being
 *  present.
 * 
 * \note This trap may NOT be called from a high-priority task handler
 * 
 * \ingroup trapset_test
 * 
 * WARNING: This trap is UNIMPLEMENTED
 */
bool TestPerform_(uint16 len, const uint16 * args);
#endif /* TRAPSET_TEST */

/**
 *  \brief Radio test pause.
 *  \return TRUE on success, else FALSE. 
 * 
 * \note This trap may NOT be called from a high-priority task handler
 * 
 * \ingroup trapset___special_inline
 */
bool TestPause(void );

/**
 *  \brief Radio test tx start. 
 *  \param lo_freq  The lo_freq to use. 
 *  \param level The level to use. The lower 8 bits are the internal gain. The upper 8 bits are
 *  the external gain. 
 *  \param mod_freq The mod_freq to use.
 *  \return TRUE on success, else FALSE. 
 * 
 * \note This trap may NOT be called from a high-priority task handler
 * 
 * \ingroup trapset___special_inline
 */
bool TestTxStart(uint16 lo_freq, uint16 level, uint16 mod_freq);

/**
 *  \brief Radio test tx data 1. 
 *  \param lo_freq  Local oscillator frequency to use. 
 *  \param level  Transmit level to use. The lower 8 bits are the internal gain. The upper 8
 *  bits are the external gain.
 *  \return TRUE on success, else FALSE. 
 * 
 * \note This trap may NOT be called from a high-priority task handler
 * 
 * \ingroup trapset___special_inline
 */
bool TestTxData1(uint16 lo_freq, uint16 level);

/**
 *  \brief Radio test tx data 2. 
 *  \param cc The cc to use. 
 *  \param level The level to use. The lower 8 bits are the internal gain. The upper 8 bits are
 *  the external gain.
 *  \return TRUE on success, else FALSE. 
 * 
 * \note This trap may NOT be called from a high-priority task handler
 * 
 * \ingroup trapset___special_inline
 */
bool TestTxData2(uint16 cc, uint16 level);

/**
 *  \brief Radio test rx. 
 *  \param lo_freq The lo_freq to use. 
 *  \param highside The high side to use. 
 *  \param attn The attn to use. 
 *  \return TRUE on success, else FALSE. 
 * 
 * \note This trap may NOT be called from a high-priority task handler
 * 
 * \ingroup trapset___special_inline
 */
bool TestRxStart(uint16 lo_freq, uint16 highside, uint16 attn);

/**
 *  \brief Radio test deep sleep.
 * 
 * \note This trap may NOT be called from a high-priority task handler
 * 
 * \ingroup trapset___special_inline
 * 
 * WARNING: This trap is UNIMPLEMENTED
 */
bool TestDeepSleep(void );

/**
 *  \brief Configure hardware loopback for PCM port. 
 *  \param pcm_mode  Chosen loopback mode. Valid values: 0, 1, 2
 * 
 * \note This trap may NOT be called from a high-priority task handler
 * 
 * \ingroup trapset___special_inline
 * 
 * WARNING: This trap is UNIMPLEMENTED
 */
bool TestPcmLb(uint16 pcm_mode);

/**
 *  \brief Radio test loop back. 
 *  \param lo_freq The lo_freq to use. 
 *  \param level The level to use.
 *  \return TRUE on success, else FALSE. 
 * 
 * \note This trap may NOT be called from a high-priority task handler
 * 
 * \ingroup trapset___special_inline
 */
bool TestLoopback(uint16 lo_freq, uint16 level);

/**
 *  \brief Configure external hardware loopback for PCM port. A block of random data is
 *  written to the PCM output port and is read back again on the PCM input port. 
 *  \param pcm_mode  Chosen loopback mode. Valid values: 0, 1, 2
 * 
 * \note This trap may NOT be called from a high-priority task handler
 * 
 * \ingroup trapset___special_inline
 * 
 * WARNING: This trap is UNIMPLEMENTED
 */
bool TestPcmExtLb(uint16 pcm_mode);

/**
 *  \brief Radio test for configuring the crystal trim value. 
 *  \param xtal_ftrim Selected crystal trim value.
 * 
 * \note This trap may NOT be called from a high-priority task handler
 * 
 * \ingroup trapset___special_inline
 * 
 * WARNING: This trap is UNIMPLEMENTED
 */
bool TestCfgXtalFtrim(uint16 xtal_ftrim);

/**
 *  \brief Play a constant tone on the PCM port (or the codec for BC02 with
 *  PSKEY_HOSTIO_MAP_SCO_CODEC set). 
 *  \param freq  Chosen frequency. 
 *  \param ampl  Chosen amplitude. 
 *  \param dc  Specifies a constant offset to add to the audio data.
 * 
 * \note This trap may NOT be called from a high-priority task handler
 * 
 * \ingroup trapset___special_inline
 * 
 * WARNING: This trap is UNIMPLEMENTED
 */
bool TestPcmTone(uint16 freq, uint16 ampl, uint16 dc);

/**
 *  \brief Turn on codec hardware for stereo loopback 
 *  \param samp_rate  Sampling rate. Valid values: 8000, 11025, 16000, 22050, 24000, 32000 and 44100 
 *  \param reroute_optn  Routing option. Valid values: 0, 1, 2, 3
 * 
 * \note This trap may NOT be called from a high-priority task handler
 * 
 * \ingroup trapset___special_inline
 * 
 * WARNING: This trap is UNIMPLEMENTED
 */
bool TestCodecStereoLb(uint16 samp_rate, uint16 reroute_optn);

/**
 *  \brief Play a constant tone on the PCM port (or the codec for BC02 with
 *  PSKEY_HOSTIO_MAP_SCO_CODEC set). 
 *  \param freq  Chosen frequency. Valid range: 0 (low) to 3 (high). 
 *  \param ampl  Chosen amplitude. Valid range: 0 (minimum) to 8 (maximum). 
 *  \param dc  Specifies a constant offset to add to the audio data. 
 *  \param interface Chosen PCM interface. A value from the \#audio_instance enumeration. 
 *  \return TRUE if successful, else FALSE.
 * 
 * \note This trap may NOT be called from a high-priority task handler
 * 
 * \ingroup trapset___special_inline
 * 
 * WARNING: This trap is UNIMPLEMENTED
 */
bool TestPcmToneIf(uint16 freq, uint16 ampl, uint16 dc, uint16 interface);

/**
 *  \brief Configure hardware loopback for PCM port. 
 *  \param pcm_mode  Chosen mode. Valid values: 0 (slave), 1 (master), 2 (Manchester slave) 
 *  \param interface Chosen PCM interface. A value from the \#audio_instance enumeration. 
 *  \return TRUE if successful, else FALSE.
 * 
 * \note This trap may NOT be called from a high-priority task handler
 * 
 * \ingroup trapset___special_inline
 * 
 * WARNING: This trap is UNIMPLEMENTED
 */
bool TestPcmLbIf(uint16 pcm_mode, uint16 interface);

/**
 *  \brief Configure external hardware loopback for PCM port. A block of random data is
 *  written to the PCM output port and is read back again on the PCM input port. 
 *  \param pcm_mode  Chosen mode. Valid values: 0 (slave), 1 (master), 2 (Manchester slave) 
 *  \param interface Chosen PCM interface. A value from the \#audio_instance enumeration. 
 *  \return TRUE if successful, else FALSE.
 * 
 * \note This trap may NOT be called from a high-priority task handler
 * 
 * \ingroup trapset___special_inline
 * 
 * WARNING: This trap is UNIMPLEMENTED
 */
bool TestPcmExtLbIf(uint16 pcm_mode, uint16 interface);
#endif
