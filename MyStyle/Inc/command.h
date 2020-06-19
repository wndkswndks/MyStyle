//command.h

#ifndef __COMMAND_H
#define __COMMAND_H


/*  			include start  			*/
#include "commonheader.h"
/*  			include end  			*/



/*  			define start  			*/
// mode=======================================//
#define CT		        			0x63745F5F	// [ct__]
#define CT_CHILD        			0x63746368	// [ctch]

#define	PANO_STAN					0x70616E6F	// [pano]
#define PANO_BITEWING				0x62697769	// [biwi]
#define PANO_TMJ1					0x746D6A31	// [tmj1]
#define PANO_TMJ2					0x746D6A32	// [tmj2]
#define PANO_SINUS					0x73696E75	// [sinu]

#define SCAN_CEPH_LA				0x6365706C	// [cepl]
#define SCAN_CEPH_PA				0x63657070	// [cepp]

#define	PACKING_MODE				0x706B6D64	// [pkmd]

#define PREC_COMPLETE    			0x70726563	// [prec]

// mode=======================================//

// ctrl=========================================//
#define KV_SETTING					0x6B767374	// [kvst]	
#define MA_SETTING					0x6D617374	// [mast]	
#define KV_REQ     					0x6B763F5F	// [kv?_]	
#define MA_REQ     					0x6D613F5F	// [ma?_]	
#define TUBE_MODE_REQ				0x74756D3F	// [tum?]	
#define X_RAY_EXP_STATE_REQ			0x6578703F	// [exp?]	
#define INVERTER_BUZZER_STATE_REQ	0x69623F5F	// [ib?_]	
#define MA_DA_VALUE_REQ				0x64613F5F	// [da?_]	
#define KV_DA_VALUE_REQ				0x64763F5F	// [dv?_]	
#define	TUBE_NORMAL_MODE    	   	0x74756E72	// [tunr]	
#define	TUBE_PULSE_MODE				0x7475706C	// [tupl]	
#define INVERTER_BUZZER_ON			0x69626F6E	// [ibon]
#define INVERTER_BUZZER_OFF			0x69626F66	// [ibof]
#define KV_DA_VALUE_SETTING			0x64767374	// [dvst]	
#define MA_DA_VALUE_SETTING			0x64617374	// [dast]	
#define TUBE_TEMP_REQ				0x74743F5F	// [tt?_]			
#define	TUBE_TEMP_THRES				0x74747468	// [ttth]	
#define TUBE_TEMP_THRES_REQ 		0x7474743F	// [ttt?]	
#define GEN_FW_REVIRSION			0x67667276	// [gfrv]

#define	PA_MOVE						0x70616D76	// [pamv]	
#define	PA_SLOW_STOP				0x70617370	// [pasp]
#define	RO_MOVE						0x726F6D76	// [romv]	
#define	RO_SLOW_STOP				0x726F7370	// [rosp]
#define	RO_MAX_SPEED				0x726F6D73	// [roms]
#define	RO_START_SPEED				0x726F7373	// [ross]
#define	RO_ACCEL_STEP				0x726F6173	// [roas]
#define	CO_MOVE						0x636F6D76	// [comv]	
#define	CO_MOVE_ACCU				0x636F6D61	// [coma]	
#define	CO_MOVE_CONST				0x636F6D63	// [comc]	
#define	SD_MOVE						0x73646D76	// [sdmv]	
#define	SD_MOVE_CONST				0x73646D63	// [sdmc]	
#define	SD_START_SPEED				0x73647373	// [sdss]
#define	SD_MAX_SPEED				0x73646D73	// [sdms]
#define SD_MOVE_PULSE				0x73646D70	// [sdmp]

#define	HL_MOVE						0x686C6D76	// [hlmv]	
#define	HL_MOVE_ACCU				0x686C6D61	// [hlma]
#define	HL_MOVE_UM					0x686C6D75	// [hlmu]
#define	HL_MOVE_CONST				0x686C6D63	// [hlmc]
#define	HR_MOVE						0x68726D76	// [hrmv]	
#define	HR_MOVE_ACCU				0x68726D61	// [hrma]
#define	HR_MOVE_UM					0x68726D75	// [hrmu]
#define	HR_MOVE_CONST				0x68726D63	// [hrmc]
#define	VT_MOVE						0x76746D76	// [vtmv]	
#define	VT_MOVE_ACCU				0x76746D61	// [vtma]
#define	VT_MOVE_UM					0x76746D75	// [vtmu]
#define	VT_MOVE_CONST				0x76746D63	// [vtmc]
#define	VB_MOVE						0x76626D76	// [vbmv]	
#define	VB_MOVE_ACCU				0x76626D61	// [vbma]
#define	VB_MOVE_UM					0x76626D75	// [vbmu]
#define	VB_MOVE_CONST				0x76626D63	// [vbmc]
#define HL_MOVE_CONST				0x686C6D63	// [hlmc]
#define HR_MOVE_CONST				0x68726D63	// [hrmc]
#define VT_MOVE_CONST				0x76746D63	// [vtmc]
#define VB_MOVE_CONST				0x76626D63	// [vbmc]

#define	PA_CT_OFFSET_POS			0x70616374	// [pact]
#define	RO_CT_OFFSET_POS			0x726F6374	// [roct]
#define CO_CT_OFFSET_POS			0x636F6374	// [coct]
#define	CT_RO_END_ANGLE				0x63726561	// [crea]
#define	CT_RO_END_TIME				0x63726574	// [cret]
#define	SCFR						0x73636672	// [scfr]	
#define	CT_CAPT_FPS					0x63667073	// [cfps]
#define	SCOUT						0x73637574	// [scut]	
#define SCTM        				0x7363746D	// [sctm]

#define	PANO_RO_END_ANGLE			0x70726561	// [prea]
#define	PANO_NOR_TBL_OPTION			0x706E746F	// [pnto]
#define	PANO_TMJ_TBL_OPTION			0x7074746F	// [ptto]
#define CANINE_BEAM_VALUE_ENABLE	0x63627665	// [cbve]	
#define CANINE_BEAM_VALUE_REQ		0x6362763F	// [cbv?]
#define PX_PANO_SET					0x70707374	// [ppst]	
#define PANO_STAN_PREC_ANGLE  		0x70707073	// [ppps]	
#define PANO_TMJ_PREC_ANGLE  		0x74707073	// [tpps]	
#define	PANO_TMJ2_PREC_ANGLE		0x74327073	// [t2ps]
#define	PA_PANO_OFFSET_POS			0x70617061	// [papa]
#define CO_PANO_OFFSET_POS			0x636F7061	// [copa]
#define PANO_STAN_CAPT_START		0x70637370	// [pcsp]	
#define PANO_TMJ_CAPT_START			0x7465736E	// [tesn]	
#define PANO_TMJ_CAPT_END			0x7465656E	// [teen]	
#define	PANO_TRIGGER_NUMBER			0x7061746E	// [patn]	
#define SELECT_BITEWING     		0x62776667  // [bwfg]	

// ctrl=========================================//

/*  			define end  			*/



/*  			enum start  			*/

/*  			enum end  				*/



/*  			stuct start  			*/
typedef struct
{
	uint8_t main_mode;
} MODE_T;
/*  			stuct end  				*/



/*  			function start  		*/
void CMD_Ctrl(UART_CMD_T);
void CMD_Mode(UART_CMD_T);

void CMD_Mode_CT();
void CMD_Mode_PANO(long);
void CMD_Mode_CEPH();
void CMD_Mode_PREC();
void CMD_ModePrintf(long);




/*  			function end  			*/

#endif
