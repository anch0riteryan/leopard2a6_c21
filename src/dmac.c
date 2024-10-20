#include <dmac.h>
#include <ppm_reader.h>
#include <samc21.h>

//#pragma data_alignment=16
DmacDescriptor DMA_DESCRIPTOR[DMAC_CH_NUM] __attribute__((aligned(16))) = { 
	{ //RADIO-CH1
		.BTCTRL.bit.VALID = 1,
		.BTCTRL.bit.EVOSEL = DMAC_BTCTRL_EVOSEL_DISABLE_Val, //event output
		.BTCTRL.bit.BLOCKACT = DMAC_BTCTRL_BLOCKACT_NOACT_Val, //DMAC_BTCTRL_BLOCKACT_NOACT_Val,
		.BTCTRL.bit.BEATSIZE = DMAC_BTCTRL_BEATSIZE_WORD_Val, //32-bit
		.BTCTRL.bit.SRCINC = 0,
		.BTCTRL.bit.DSTINC = 0,
		.BTCTRL.bit.STEPSEL = 0, //DMAC_BTCTRL_STEPSEL_DST_Val , DMAC_BTCTRL_STEPSEL_SRC_Val
		.BTCTRL.bit.STEPSIZE = 0,

		.BTCNT.bit.BTCNT = 0xFFFF,

		.SRCADDR.reg = (uint32_t ) &(TCC0->CC[0].reg),
		.DSTADDR.reg = (uint32_t ) (ppm_width_raw + 0),

		.DESCADDR.bit.DESCADDR = (uint32_t ) 0x0 //Next Descriptor
	},
	{ //RADIO-CH2
		.BTCTRL.bit.VALID = 1,
		.BTCTRL.bit.EVOSEL = DMAC_BTCTRL_EVOSEL_DISABLE_Val, //event output
		.BTCTRL.bit.BLOCKACT = DMAC_BTCTRL_BLOCKACT_NOACT_Val,
		.BTCTRL.bit.BEATSIZE = DMAC_BTCTRL_BEATSIZE_WORD_Val, //32-bit
		.BTCTRL.bit.SRCINC = 0,
		.BTCTRL.bit.DSTINC = 0,
		.BTCTRL.bit.STEPSEL = 0, //DMAC_BTCTRL_STEPSEL_DST_Val , DMAC_BTCTRL_STEPSEL_SRC_Val
		.BTCTRL.bit.STEPSIZE = 0,

		.BTCNT.bit.BTCNT = 0xFFFF,

		.SRCADDR.reg = (uint32_t ) &(TCC0->CC[1].reg),
		.DSTADDR.reg = (uint32_t ) (ppm_width_raw + 1),

		.DESCADDR.bit.DESCADDR = (uint32_t ) 0x0 //Next Descriptor
	},
	{ //RADIO-CH3
		.BTCTRL.bit.VALID = 1,
		.BTCTRL.bit.EVOSEL = DMAC_BTCTRL_EVOSEL_DISABLE_Val, //event output
		.BTCTRL.bit.BLOCKACT = DMAC_BTCTRL_BLOCKACT_NOACT_Val,
		.BTCTRL.bit.BEATSIZE = DMAC_BTCTRL_BEATSIZE_WORD_Val, //32-bit
		.BTCTRL.bit.SRCINC = 0,
		.BTCTRL.bit.DSTINC = 0,
		.BTCTRL.bit.STEPSEL = 0, //DMAC_BTCTRL_STEPSEL_DST_Val , DMAC_BTCTRL_STEPSEL_SRC_Val
		.BTCTRL.bit.STEPSIZE = 0,

		.BTCNT.bit.BTCNT = 0xFFFF,

		.SRCADDR.reg = (uint32_t ) &(TCC0->CC[2].reg),
		.DSTADDR.reg = (uint32_t ) (ppm_width_raw + 2),

		.DESCADDR.bit.DESCADDR = (uint32_t ) 0x0 //Next Descriptor
	},
	{ //RADIO-CH4
		.BTCTRL.bit.VALID = 1,
		.BTCTRL.bit.EVOSEL = DMAC_BTCTRL_EVOSEL_DISABLE_Val, //event output
		.BTCTRL.bit.BLOCKACT = DMAC_BTCTRL_BLOCKACT_NOACT_Val,
		.BTCTRL.bit.BEATSIZE = DMAC_BTCTRL_BEATSIZE_WORD_Val, //32-bit
		.BTCTRL.bit.SRCINC = 0,
		.BTCTRL.bit.DSTINC = 0,
		.BTCTRL.bit.STEPSEL = 0, //DMAC_BTCTRL_STEPSEL_DST_Val , DMAC_BTCTRL_STEPSEL_SRC_Val
		.BTCTRL.bit.STEPSIZE = 0,

		.BTCNT.bit.BTCNT = 0xFFFF,

		.SRCADDR.reg = (uint32_t ) &(TCC0->CC[3].reg),
		.DSTADDR.reg = (uint32_t ) (ppm_width_raw + 3),

		.DESCADDR.bit.DESCADDR = (uint32_t ) 0x0 //Next Descriptor
	},
	{ //RADIO-CH5
		.BTCTRL.bit.VALID = 1,
		.BTCTRL.bit.EVOSEL = DMAC_BTCTRL_EVOSEL_DISABLE_Val, //event output
		.BTCTRL.bit.BLOCKACT = DMAC_BTCTRL_BLOCKACT_NOACT_Val,
		.BTCTRL.bit.BEATSIZE = DMAC_BTCTRL_BEATSIZE_WORD_Val, //32-bit
		.BTCTRL.bit.SRCINC = 0,
		.BTCTRL.bit.DSTINC = 0,
		.BTCTRL.bit.STEPSEL = 0, //DMAC_BTCTRL_STEPSEL_DST_Val , DMAC_BTCTRL_STEPSEL_SRC_Val
		.BTCTRL.bit.STEPSIZE = 0,

		.BTCNT.bit.BTCNT = 0xFFFF,

		.SRCADDR.reg = (uint32_t) &(TCC1->CC[0].reg),
		.DSTADDR.reg = (uint32_t) (ppm_width_raw + 4),

		.DESCADDR.bit.DESCADDR = (uint32_t) 0x0 //Next Descriptor
	},
	{ //RADIO-CH6
		.BTCTRL.bit.VALID = 1,
		.BTCTRL.bit.EVOSEL = DMAC_BTCTRL_EVOSEL_DISABLE_Val, //event output
		.BTCTRL.bit.BLOCKACT = DMAC_BTCTRL_BLOCKACT_NOACT_Val,
		.BTCTRL.bit.BEATSIZE = DMAC_BTCTRL_BEATSIZE_WORD_Val, //32-bit
		.BTCTRL.bit.SRCINC = 0,
		.BTCTRL.bit.DSTINC = 0,
		.BTCTRL.bit.STEPSEL = 0, //DMAC_BTCTRL_STEPSEL_DST_Val , DMAC_BTCTRL_STEPSEL_SRC_Val
		.BTCTRL.bit.STEPSIZE = 0,

		.BTCNT.bit.BTCNT = 0xFFFF,

		.SRCADDR.reg = (uint32_t) &(TCC1->CC[1].reg),
		.DSTADDR.reg = (uint32_t) (ppm_width_raw + 5),

		.DESCADDR.bit.DESCADDR = (uint32_t) 0x0 //Next Descriptor
	},
	{ //RADIO-CH7
		.BTCTRL.bit.VALID = 1,
		.BTCTRL.bit.EVOSEL = DMAC_BTCTRL_EVOSEL_DISABLE_Val, //event output
		.BTCTRL.bit.BLOCKACT = DMAC_BTCTRL_BLOCKACT_NOACT_Val,
		.BTCTRL.bit.BEATSIZE = DMAC_BTCTRL_BEATSIZE_WORD_Val, //32-bit
		.BTCTRL.bit.SRCINC = 0,
		.BTCTRL.bit.DSTINC = 0,
		.BTCTRL.bit.STEPSEL = 0, //DMAC_BTCTRL_STEPSEL_DST_Val , DMAC_BTCTRL_STEPSEL_SRC_Val
		.BTCTRL.bit.STEPSIZE = 0,

		.BTCNT.bit.BTCNT = 0xFFFF,

		.SRCADDR.reg = (uint32_t) &(TCC2->CC[0].reg),
		.DSTADDR.reg = (uint32_t) (ppm_width_raw + 6),

		.DESCADDR.bit.DESCADDR = (uint32_t) 0x0 //Next Descriptor
	},
	{ //RADIO-CH8
		.BTCTRL.bit.VALID = 1,
		.BTCTRL.bit.EVOSEL = DMAC_BTCTRL_EVOSEL_DISABLE_Val, //event output
		.BTCTRL.bit.BLOCKACT = DMAC_BTCTRL_BLOCKACT_NOACT_Val,
		.BTCTRL.bit.BEATSIZE = DMAC_BTCTRL_BEATSIZE_WORD_Val, //32-bit
		.BTCTRL.bit.SRCINC = 0,
		.BTCTRL.bit.DSTINC = 0,
		.BTCTRL.bit.STEPSEL = 0, //DMAC_BTCTRL_STEPSEL_DST_Val , DMAC_BTCTRL_STEPSEL_SRC_Val
		.BTCTRL.bit.STEPSIZE = 0,

		.BTCNT.bit.BTCNT = 0xFFFF,

		.SRCADDR.reg = (uint32_t) &(TCC2->CC[1].reg),
		.DSTADDR.reg = (uint32_t) (ppm_width_raw + 7),

		.DESCADDR.bit.DESCADDR = (uint32_t) 0x0 //Next Descriptor
	},
	{ //8
		.BTCTRL.bit.VALID = 0,
		.BTCTRL.bit.EVOSEL = DMAC_BTCTRL_EVOSEL_DISABLE_Val, //event output
		.BTCTRL.bit.BLOCKACT = DMAC_BTCTRL_BLOCKACT_NOACT_Val,
		.BTCTRL.bit.BEATSIZE = DMAC_BTCTRL_BEATSIZE_WORD_Val, //32-bit
		.BTCTRL.bit.SRCINC = 0,
		.BTCTRL.bit.DSTINC = 0,
		.BTCTRL.bit.STEPSEL = 0, //DMAC_BTCTRL_STEPSEL_DST_Val , DMAC_BTCTRL_STEPSEL_SRC_Val
		.BTCTRL.bit.STEPSIZE = 0,

		.BTCNT.bit.BTCNT = 0,

		.SRCADDR.reg = 0,
		.DSTADDR.reg = 0,

		.DESCADDR.bit.DESCADDR = (uint32_t) 0x0 //Next Descriptor
	},
	{ //9
		.BTCTRL.bit.VALID = 0,
		.BTCTRL.bit.EVOSEL = DMAC_BTCTRL_EVOSEL_DISABLE_Val, //event output
		.BTCTRL.bit.BLOCKACT = DMAC_BTCTRL_BLOCKACT_NOACT_Val,
		.BTCTRL.bit.BEATSIZE = DMAC_BTCTRL_BEATSIZE_WORD_Val, //32-bit
		.BTCTRL.bit.SRCINC = 0,
		.BTCTRL.bit.DSTINC = 0,
		.BTCTRL.bit.STEPSEL = 0, //DMAC_BTCTRL_STEPSEL_DST_Val , DMAC_BTCTRL_STEPSEL_SRC_Val
		.BTCTRL.bit.STEPSIZE = 0,

		.BTCNT.bit.BTCNT = 0,

		.SRCADDR.reg = 0,
		.DSTADDR.reg = 0,

		.DESCADDR.bit.DESCADDR = (uint32_t) 0x0 //Next Descriptor
	},
	{ //10
		.BTCTRL.bit.VALID = 1,
		.BTCTRL.bit.EVOSEL = DMAC_BTCTRL_EVOSEL_DISABLE_Val, //event output
		.BTCTRL.bit.BLOCKACT = DMAC_BTCTRL_BLOCKACT_NOACT_Val,
		.BTCTRL.bit.BEATSIZE = DMAC_BTCTRL_BEATSIZE_WORD_Val, //32-bit
		.BTCTRL.bit.SRCINC = 0,
		.BTCTRL.bit.DSTINC = 0,
		.BTCTRL.bit.STEPSEL = 0, //DMAC_BTCTRL_STEPSEL_DST_Val , DMAC_BTCTRL_STEPSEL_SRC_Val
		.BTCTRL.bit.STEPSIZE = 0,

		.BTCNT.bit.BTCNT = 0xFFFF,

		.SRCADDR.reg = (uint32_t) 0,
		.DSTADDR.reg = (uint32_t) 0,

		.DESCADDR.bit.DESCADDR = (uint32_t) 0x0 //Next Descriptor
	},
	{ //11
		.BTCTRL.bit.VALID = 1,
		.BTCTRL.bit.EVOSEL = DMAC_BTCTRL_EVOSEL_DISABLE_Val, //event output
		.BTCTRL.bit.BLOCKACT = DMAC_BTCTRL_BLOCKACT_NOACT_Val,
		.BTCTRL.bit.BEATSIZE = DMAC_BTCTRL_BEATSIZE_WORD_Val, //32-bit
		.BTCTRL.bit.SRCINC = 0,
		.BTCTRL.bit.DSTINC = 0,
		.BTCTRL.bit.STEPSEL = 0, //DMAC_BTCTRL_STEPSEL_DST_Val , DMAC_BTCTRL_STEPSEL_SRC_Val
		.BTCTRL.bit.STEPSIZE = 0,

		.BTCNT.bit.BTCNT = 0xFFFF,

		.SRCADDR.reg = (uint32_t) 0,
		.DSTADDR.reg = (uint32_t) 0,

		.DESCADDR.bit.DESCADDR = (uint32_t) 0x0 //Next Descriptor
	}
};

//#pragma data_alignment=16
DmacDescriptor DMA_DESCRIPTOR_WRITEBACK[DMAC_CH_NUM] __attribute__((aligned(16))) ;

void DMAC_Handler () {
	uint8_t channel;

	for (channel = 0; channel < 12; channel ++) {
		if (DMAC->INTSTATUS.vec.CHINT >> channel & 0x01) {
			DMAC->CHID.bit.ID = channel;
			if (DMAC->CHINTFLAG.bit.SUSP) {
				DMAC->CHCTRLB.bit.CMD = DMAC_CHCTRLB_CMD_RESUME_Val;
				DMAC->CHCTRLA.bit.ENABLE = 1;

				DMAC->CHINTFLAG.reg = DMAC_CHINTFLAG_SUSP;
			}

			if (DMAC->CHINTFLAG.bit.TCMPL) {
				DMAC->CHCTRLA.bit.ENABLE = 1;
				DMAC->CHCTRLB.bit.CMD = DMAC_CHCTRLB_CMD_RESUME_Val;
				DMAC->CHINTFLAG.reg = DMAC_CHINTFLAG_TCMPL;
			}

			if (DMAC->CHINTFLAG.bit.TERR) {
				DMAC->CHCTRLB.bit.CMD = DMAC_CHCTRLB_CMD_RESUME_Val;
				DMAC->CHCTRLA.bit.ENABLE = 1;

				DMAC->CHINTFLAG.reg = DMAC_CHINTFLAG_TERR;
			}
		}
	}
}

void init_dmac () {
	MCLK->AHBMASK.bit.DMAC_ = 1;
	MCLK->APBBMASK.bit.HMATRIXHS_ = 1;

	DMAC->CTRL.bit.SWRST = 1;
	while (DMAC->CTRL.bit.SWRST);

	DMAC->BASEADDR.bit.BASEADDR = (uint32_t) DMA_DESCRIPTOR;
	DMAC->WRBADDR.bit.WRBADDR   = (uint32_t) DMA_DESCRIPTOR_WRITEBACK;

	//radio-ch1
	DMAC->CHID.bit.ID = 0;
	DMAC->CHCTRLB = (DMAC_CHCTRLB_Type) {
		.bit.EVACT = DMAC_CHCTRLB_EVACT_NOACT_Val,
		.bit.EVIE = 0,
		.bit.EVOE = 0,
		.bit.LVL  = 0,
		.bit.TRIGSRC = TCC0_DMAC_ID_MC_0,
		.bit.TRIGACT = DMAC_CHCTRLB_TRIGACT_BEAT_Val
	};
	DMAC->CHINTENSET.bit.TCMPL = 1;
	DMAC->CHCTRLA.bit.ENABLE = 1;

	//radio-ch2
	DMAC->CHID.bit.ID = 1;
	DMAC->CHCTRLB = (DMAC_CHCTRLB_Type) {
		.bit.EVACT = DMAC_CHCTRLB_EVACT_NOACT_Val,
		.bit.EVIE = 0,
		.bit.EVOE = 0,
		.bit.LVL  = 0,
		.bit.TRIGSRC = TCC0_DMAC_ID_MC_1,
		.bit.TRIGACT = DMAC_CHCTRLB_TRIGACT_BEAT_Val
	};
	DMAC->CHCTRLA.bit.ENABLE = 1;

	//radio-ch3
	DMAC->CHID.bit.ID = 2;
	DMAC->CHCTRLB = (DMAC_CHCTRLB_Type) {
		.bit.EVACT = DMAC_CHCTRLB_EVACT_NOACT_Val,
		.bit.EVIE = 0,
		.bit.EVOE = 0,
		.bit.LVL  = 0,
		.bit.TRIGSRC = TCC0_DMAC_ID_MC_2,
		.bit.TRIGACT = DMAC_CHCTRLB_TRIGACT_BEAT_Val
	};
	DMAC->CHCTRLA.bit.ENABLE = 1;

	//radio-ch4
	DMAC->CHID.bit.ID = 3;
	DMAC->CHCTRLB = (DMAC_CHCTRLB_Type) {
		.bit.EVACT = DMAC_CHCTRLB_EVACT_NOACT_Val,
		.bit.EVIE = 0,
		.bit.EVOE = 0,
		.bit.LVL  = 0,
		.bit.TRIGSRC = TCC0_DMAC_ID_MC_3,
		.bit.TRIGACT = DMAC_CHCTRLB_TRIGACT_BEAT_Val
	};
	DMAC->CHCTRLA.bit.ENABLE = 1;

	//radio-ch5
	DMAC->CHID.bit.ID = 4;
	DMAC->CHCTRLB = (DMAC_CHCTRLB_Type) {
		.bit.EVACT = DMAC_CHCTRLB_EVACT_NOACT_Val,
		.bit.EVIE = 0,
		.bit.EVOE = 0,
		.bit.LVL  = 0,
		.bit.TRIGSRC = TCC1_DMAC_ID_MC_0,
		.bit.TRIGACT = DMAC_CHCTRLB_TRIGACT_BEAT_Val
	};
	DMAC->CHCTRLA.bit.ENABLE = 1;

	//radio-ch6
	DMAC->CHID.bit.ID = 5;
	DMAC->CHCTRLB = (DMAC_CHCTRLB_Type) {
		.bit.EVACT = DMAC_CHCTRLB_EVACT_NOACT_Val,
		.bit.EVIE = 0,
		.bit.EVOE = 0,
		.bit.LVL  = 0,
		.bit.TRIGSRC = TCC1_DMAC_ID_MC_1,
		.bit.TRIGACT = DMAC_CHCTRLB_TRIGACT_BEAT_Val
	};
	DMAC->CHCTRLA.bit.ENABLE = 1;

	//radio-ch7
	DMAC->CHID.bit.ID = 6;
	DMAC->CHCTRLB = (DMAC_CHCTRLB_Type) {
		.bit.EVACT = DMAC_CHCTRLB_EVACT_NOACT_Val,
		.bit.EVIE = 0,
		.bit.EVOE = 0,
		.bit.LVL  = 0,
		.bit.TRIGSRC = TCC2_DMAC_ID_MC_0,
		.bit.TRIGACT = DMAC_CHCTRLB_TRIGACT_BEAT_Val
	};
	DMAC->CHCTRLA.bit.ENABLE = 1;

	//radio-ch8
	DMAC->CHID.bit.ID = 7;
	DMAC->CHCTRLB = (DMAC_CHCTRLB_Type) {
		.bit.EVACT = DMAC_CHCTRLB_EVACT_NOACT_Val,
		.bit.EVIE = 0,
		.bit.EVOE = 0,
		.bit.LVL  = 0,
		.bit.TRIGSRC = TCC2_DMAC_ID_MC_1,
		.bit.TRIGACT = DMAC_CHCTRLB_TRIGACT_BEAT_Val
	};
	DMAC->CHCTRLA.bit.ENABLE = 1;

	if (DSU->STATUSB.bit.DBGPRES) {
		DMAC->DBGCTRL.bit.DBGRUN = 1;
	}

	DMAC->CTRL.bit.LVLEN0 = 1;
	DMAC->CTRL.bit.DMAENABLE = 1;
}
