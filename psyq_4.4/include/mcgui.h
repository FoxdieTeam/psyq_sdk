/*
 * $PSLibId: Run-time Library Release 4.4$
 */
#ifndef _MCGUI_H_
#define _MCGUI_H_


#define NEGICON_A	(0x20)
#define NEGICON_B	(0x10)

#define MOUSE_LBUTTON	(0x08)
#define MOUSE_RBUTTON	(0x04)


/* TEXTURE���\���� */

typedef struct {
	unsigned long* addr;
} sMcGuiTexture;


/* �������[�J�[�h���\���� */

typedef struct {
	char file[21];
	char title[65];
	char frame;
	char block;
	long dataBytes;
	unsigned long* iconAddr;
	unsigned long* dataAddr;
} sMcGuiCards;

/* BG ���\���� */

typedef struct {
	short mode;
	signed char scrollDirect;	/* 0:Up 1:Up&Left 2:Left 3:Down&left 4:Down ...*/
	signed char scrollSpeed;	/* 0:no scroll 1:1/60 2:1/30 3:1/20 */
	unsigned long* timadr;
} sMcGuiBg;

/* Cursor ���\���� */
typedef struct {
	char type;
	unsigned char r;
	unsigned char g;
	unsigned char b;
} sMcGuiCursor;

/* BGM�A���ʉ� ���\���� */

typedef struct {
	int MVOL;
	struct {
		int isbgm;
		unsigned long* seq;
		unsigned long* vh;
		unsigned long* vb;
		int SVOL;
		int isReverb;
		int reverbType;
		int reverbDepth;
	} bgm;
	struct {
		int isse;
		unsigned long* vh;
		unsigned long* vb;
		int vol;
		int prog;
		int TONE_OK;
		int TONE_CANCEL;
		int TONE_CURSOR;
		int TONE_ERROR;
	} se;
} sMcGuiSnd;

/* �R���g���[���֘A���\���� */

typedef struct {
	volatile unsigned char* buf[2];
	struct {
		int flag;
		unsigned long BUTTON_OK;
		unsigned long BUTTON_CANCEL;
	} type1;
	struct {
		int flag;
		unsigned long BUTTON_OK;
		unsigned long BUTTON_CANCEL;
	} type2;
	struct {
		int flag;
		unsigned long BUTTON_OK;
		unsigned long BUTTON_CANCEL;
	} type3;
	struct {
		int flag;
		unsigned long BUTTON_OK;
		unsigned long BUTTON_CANCEL;
	} type4;
} sMcGuiController;



/* �������[�J�[�h�Ǘ���ʃR���t�B�O�\���� */

typedef struct {
	sMcGuiCards cards;		/* �������[�J�[�h��� */
	sMcGuiBg bg;			/* BG��� */
	sMcGuiController controller;	/* �R���g���[���֘A��� */
	sMcGuiSnd sound;		/* �a�f�l���ʉ���� */
	sMcGuiTexture texture;		/* �e�N�X�`����� */
	sMcGuiCursor cursor;		/* �J�[�\����� */
} McGuiEnv;

extern int McGuiSave(McGuiEnv* env);
extern int McGuiLoad(McGuiEnv* env);

#endif _MCGUI_H_
