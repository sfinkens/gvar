
#ifndef BLK0_H
#define BLK0_H

//#include <stream.h>
#include "include/types.h"
#include "block0/attitudeAngle.h"
#include "block0/biasStatistics.h"
#include "block0/calibration.h"
#include "block0/iscan.h"

/* pg 68 , goes i-m, oge specs */

#define BLOCK0_BSZ 8042

class ImagerDoc{ 
public:
  // to align the block on 4byte boundaries???
  //  floats, 4bytes ints and 8byte values need to be aligned to 4bytes???
  uchar8 junk[2]; 



  uchar8 Spcid;/* 1 */
  uchar8 ground_system_id;/* 2 */


  //   0- 277 Instrument and Scan Status 

  ISCAN Iscan;/* 3 6  byte 3 CHANGES  */   
  

  uchar8 Idsub; /* 7 */
  uchar8 IdsubIR[7]; /* 8 14 */

  uchar8 IdsubVis[8];/* 15 22 */

  CdaTime T_sps_current ; /* 23 30 this is the SPS current time ....  CHANGES  */
  CdaTime T_current_header ; /* 31 38  CHANGES  */
  CdaTime T_current_trailer ; /* 39 46  CHANGES  */
  CdaTime T_lagged_header ; /* 47 54  CHANGES  */
  CdaTime T_lagged_trailer ; /* 55 62  CHANGES  */

  CdaTime T_priority_framestart ; /* 63 70 */
  CdaTime T_normal_framestart ; /* 71 78 */

  CdaTime Tispc ; /* 79 86    CHANGES  */
  CdaTime Tiecl ; /* 87 94   */
  CdaTime Tibbc ; /* 95 102  */
  CdaTime Tistr ; /*103 110  */
  CdaTime Tlran ; /*111 118  */
  CdaTime Tiirt ; /*119 126  */
  CdaTime Tivit ; /*127 134  */
  CdaTime Tclmt ; /*135 142  */
  CdaTime Tiona ; /*143 150  */

  uint16 rel_scan_count; /*151 152  CHANGES */
  uint16 abs_scan_count; /*153 154  CHANGES */

  uint16 N_Line_In_Scan; /*155 156  CHANGES */
  uint16 W_pix_of_frame; /*157 158*/

  uint16 E_pix_of_frame; /*159 160*/
  uint16 N_line_of_frame; /*161 162*/

  uint16 S_line_of_frame; /*163 164*/

  uint16 pix_of_zero_az; /*165 166*/

  uint16 line_of_zero_elev; /*167 168*/
  uint16 scan_of_zero_elev; /*169 170*/

  uint16 Line_Of_Subsat;    /*171 172*/
  uint16 Pix_Of_Subsat;     /*173 174*/

  SelFloat  Subsat_Lat; /*175 178*/
  SelFloat  Subsat_Lon; /*179 182*/

  uchar8 Czone; /*183    CHANGES */
  uchar8 V_Detect_In_Block3; /*184*/
  uint16 G1cnt; /*185 186  CHANGES */

  uint16 G2cnt; /*187 188 CHANGES */
  uint16 EQ_Pix_Bias; /*189 190*/

  uint16 NS_Line_Bias; /*191 192*/
  uchar8 iscan_parity; /* 193  ISCP1  Odd parity byte computed for words 3-4 (part of ISCAN).   CHANGES */
  uchar8 w194_spare;   /* 194  Spare - not used */

  SelFloat Idber; /* 195-198  IDBER  Current raw data Bit Error Rate (BER) - the most recent measure of raw data error rate.									 */
  SelFloat Range; /* 199-202  RANGE  Most recently computed range - the number of 50-MHz clock counts for signal transmission from satellite to ground.  					 */
  SelFloat Gpath; /* 203-206  GPATH  Most recent range calibration ground path delay: the number of 50-MHz clock counts that the GVAR signal takes to transit through CDA station equipment.  */
  SelFloat Xmsne; /* 207-210  XMSNE  call tower range calibration value - the number of 50-MHz clock counts that the GVAR signal takes to transit the satellite transmission electronics.     */

  CdaTime Tgpat; /*211 218*/
  CdaTime Txmsn; /*219 226*/

  uint16 Istim; /*227 228 CHANGES */

  uchar8 frame_number; /*229*/
  uchar8 Imode; /*230*/

  SelFloat NW_lat_of_frame; /*231 234*/
  SelFloat NW_lon_of_frame; /*235 238*/
  SelFloat SE_lat_of_frame; /*239 242*/
  SelFloat SE_lon_of_frame; /*243 246*/

  uchar8 gain_table_index;    /* 247 IG2TN Second order gain table index number.   CHANGES */
  uchar8 iscan_parity_copy2; /* 248 ISCP2 Repeat of ISCP1 (see word 193)  CHANGES */
  uchar8 iscan_3_4[2];    /* 249-250 ISCA2 Repeat of  words 3-4 (part of ISCAN)  CHANGES */
  CdaTime T_current_framestart ; /* 251-258 CIFST Current Imager Frame Start Time.  version 1+ */

  uchar8 w259_277[19]; /* 259-277  Spares - not used  */
  uchar8 Parity_1_277; /*278 CHANGES */




  /* see goes-i 
   * Imager Documentation, Block 0 Format Definition 
   * Orbit and Attitude Parameters 
   */

  uchar8 Imc_identifier[4]; /* 279 282*/
  uchar8 w283_94[12]; /* 283 294*/

  SelFloat ReferenceLongitude; /* 295 298*/
  SelFloat ReferenceRadialDistance; /* 299 302*/
  SelFloat ReferenceLatitude; /* 303 306*/
  SelFloat ReferenceOrbitYaw; /* 307 310*/
  SelFloat ReferenceAttitudeRoll; /* 311 314*/
  SelFloat ReferenceAttitudePitch; /* 315 318*/
  SelFloat ReferenceAttitudeYaw; /* 319 322*/

  CdaTime EpochDate; /* 323 330*/

  SelFloat IMCenableFromEpoch; /* 331 334*/
  SelFloat CompensationRoll; /* 335 338*/
  SelFloat CompensationPitch; /* 339 342*/
  SelFloat CompensationYaw; /* 343 346*/
  SelFloat ChangeLongitude[13]; /* 347 398*/
  SelFloat ChangeRadialDistance[11]; /* 399 442*/
  SelFloat SineGeocentricLatitude[9]; /* 443 478*/
  SelFloat SineOrbitYaw[9]; /* 479 514*/
  SelFloat DailySolarRate; /* 515 518*/
  SelFloat ExponentialStartFromEpoch; /* 519 522*/

  AttitudeAngle RollAngle; /* 523 742*/
  AttitudeAngle PitchAngle; /* 743 962*/
  AttitudeAngle YawAngle; /* 963 1182*/
  AttitudeAngle RollMisalignment; /*1183 1402*/
  AttitudeAngle PitchMisalignment; /*1403 1662*/

  uchar8 w1623_625[3]; /*1623 1625*/
  uchar8 Parity_279_1625; /*1626 */





  //1627-2306 Scan Reference Data 

  uchar8 Coregisteration_table_id[4]; /*1627 1630*/
  uchar8 East_west_half_hourly_correction_terms[48]; /*1631 1678*/
  uchar8 Index_of_correction_term_currently_active; /*1679 */
  uchar8 w1680_1690[11]; /*1680 1690*/

  uint16 w1691_782[46]; 
  uint16 w1783_874[46];
  uint16 w1875_966[46];
  uint16 w1967_2058[46];

  uchar8 w2059_80[22];
  uchar8 w2081_102[22];
  uchar8 w2103_24[22];
  uchar8 w2125_46[22];
  uint16 Block_telemetry_word[2][39] ; /* 2147 2302 */
  uchar8 w2303_5[3]; /* 2305 2305 */
  uchar8 Parity_1691_2305; /* 2306 */




  //2307-5386 Grid Data 

  uchar8 Grid1Detector[512]; /*2307 2818*/
  uchar8 Grid2Detector[512]; /*2819 3330*/

  uint16 Grid1Pixel[512]; /*3331 4353*/
  uint16 Grid2Pixel[512]; /*4355 5378*/
  
  uint16 Gridset1RevLevel; /*5379 5380*/
  uint16 Gridset2RevLevel; /*5381 5382*/

  uchar8 w5383_85[3]; /*5383 5385*/
  uchar8 Parity_2307_5385; /*5386 */
  


  //5387-6304 Scan Reference and Calibration Data 

  uint16 w5387_478[46];
  uint16 w5479_570[46];
  CdaTime Tophed; /* 5571 5578 */
  CdaTime Totrl ; /* 2279 5586 */

  /* ir calibratrion */
  SelFloat  Iwbias[7]; /* 5587 5614*/
  SelFloat  Igain1[7]; /* 5615 5642*/
  SelFloat  Igain2[7]; /* 5643 5670*/
  SelFloat  Ibrate[7]; /* 5671 5698*/
  
  CdaTime Tod_of_westernmost_ir_pixel; /* 5699 5706 */
  
  BiasStatistics ImagerIRclamped ; /* 5707 5970 */ 
  BiasStatistics ImagerIRdrift ; /* 5971 6234 */

  uchar8 NS_half_hourly_correction_terms[48];  /* 6235 6282 */
  uchar8 Scan_clamp_e_w_clipping_edge_limb_offset[4]; /* 6283 6286 */
  uchar8 w6287_303[17] ; /* 6287 6203 */
  uchar8 Parity_5387_6303 ; /* 6304 */
  


  //6305-8040 Factory Parameters/8th IR detector Calibration Data 

  uchar8 ns_cycles ; /* 6305 */
  uchar8 ew_cycles ; /* 6306 */
  uint16 ns_incr ; /* 6307 6308 */
  uint16 ew_incr ; /* 6309 6310 */
  
  uint16 Vis_detector_x_offset[8]; /* 6311 6325 */
  uint16 Ir_detector_x_offset[14]; /* 6326 6354 */
  uint16 Vis_detector_y_offset[8]; /* 6355 6369 */
  uint16 Ir_detector_y_offset[14]; /* 6370 6398 */

  SelFloat Ivcrb[8]; /* 6399 6430 */
  SelFloat Ivcr1[8]; /* 6431 6462 */
  SelFloat Ivcr2[8]; /* 6463 6494 */
  SelFloat Ivral;    /* 6495 6498 */
  
  SelFloat Iicrb[2][7] ; /* 6499 6554 */
  SelFloat Iicr1[2][7] ; /* 6555 6610 */
  SelFloat Iicr2[2][7] ; /* 6611 6666 */
  SelFloat Iisfb[2][7] ; /* 6667 6722 */
  SelFloat Iisf1[2][7] ; /* 6723 6778 */
  SelFloat Ig2it[2][7][4] ; /* 6779 7002 */
  SelFloat Ig2bp[4] ; /* 7003 7018 */
  SelFloat Ibbtr[2][7][4] ; /* 7019 7242 */
  
  uchar8 w7234_366[124]; /* 7243 7336 */

  Calibration Imager; /* 7367 8014 */
  
  SelFloat Patch_control_voltage_gain; /* 8015 8018 */ 
  SelFloat Patch_control_voltage_bias; /* 8019 8022 */
  SelFloat Instrument_current_gain ;   /* 8023 8026 */
  SelFloat Instrument_current_bias;    /* 8027 8030 */
  
  uchar8 w8031_39[9] ; /* 8031 8039 */
  uchar8 Parity_6305_8039; /* 8040 */
  uint16 CRC; /* 8041 8042 */

public: 
  ImagerDoc();
  int copy(void * in );
  int check_copy(void * in );
  int duplicate(void * in );
  int parity_check(void * in );


  void Dframe(ostream & out); 
  void Ddump_all(ostream & out); 
  void block0timeText(ostream & out); 
  void block0time(ostream & out );
  void NavigationParameters(ostream & out);
  void NavigationFiles(ostream & out1, ostream & out2);

  uint16 crc();  // CRC word

  char spcid(); // SpaceCraft ID
  uchar8 * addr(); // address of imagerdoc

  int instrument(); // Instrument

  int imc(); 

  int line_to_scan(int this_line);

  int scan_to_line(int this_scan);

  int pix_to_aligned_pix(int this_pix);
  int line_to_aligned_line(int this_line);


  void reset();// Reset used variables
  void ByteSwap(void);
};

inline uint16 ImagerDoc::crc() { return CRC; }

inline char   ImagerDoc::spcid() { return  Spcid;} 
inline uchar8 * ImagerDoc::addr()  { return &Spcid;} 

inline int ImagerDoc::instrument() { return imager; }

inline void ImagerDoc::reset() {G1cnt = 0; G2cnt = 0; }

#endif // BLK0_H



