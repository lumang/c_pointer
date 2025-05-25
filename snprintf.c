#include<stdio.h>
#include<time.h>
typedef unsigned short  uint16_t;
typedef unsigned char   uint8_t;

typedef struct
{
	uint16_t eventCode;       //发生事件
	const char* eventString; //事件描述
}EventDesc_t; //事件描述结构体
typedef enum
{
    EVENT_TYPE_RSV0         = 0,		//	0	预留 
    EVENT_TYPE_NORMAL       = 1,		//	1	正常 
    EVENT_TYPE_FFIRE_ALM    = 2,		//	2	首火警 
    EVENT_TYPE_FIRE_ALM     = 3,		//	3	火警 
    EVENT_TYPE_ELEC_FIRE_ALARM = 4,		//	4	电气火灾报警 
    EVENT_TYPE_LEL_LOW_ALARM = 5,		//	5	可燃气体低限报警 
    EVENT_TYPE_LEL_HIGH_ALARM = 6,		//	6	可燃气体高限报警 
    EVENT_TYPE_LEL_OVER_ALARM = 7,    //	7	可燃气体超量程报警 
    // EVENT_TYPE_       = ,    //	8	电气火灾预警 
    EVENT_TYPE_CHECK_ALM    = 9,    	//	9	确认故障信息、火灾报警信息 
    // EVENT_TYPE_       = ,    //	10～18	预留 
    EVENT_TYPE_STARTUP      = 19,    	//	19	启动 
    EVENT_TYPE_STARTUP_A    = 20,    	//	20	自动启动 
    EVENT_TYPE_STARTUP_M    = 21,    //	21	手动启动 
    EVENT_TYPE_EMR_START = 22,    //	22	现场急启 
    EVENT_TYPE_STARTUP_L    = 23,    //	23	联动启动 
    EVENT_TYPE_GAS_FIRE_DELAY = 24,    //	24	气体灭火开始延时 
    EVENT_TYPE_GAS_SPRAY = 25,    //	25	气体喷洒/启动喷洒 
    EVENT_TYPE_FEEDBACK= 26,    //	26	反馈 
    EVENT_TYPE_SPRAY_FEEDBACK = 27,    //	27	喷洒反馈 
    EVENT_TYPE_FEEDBACK_RLS = 28,    //	28	反馈撤销 
    EVENT_TYPE_STOP         = 29,    //	29	停止 
    EVENT_TYPE_EMR_STOP = 30,    //	30	现场急停 
    // EVENT_TYPE_       = ,    //	31	消火栓系统、自动喷淋系统水压低 
    // EVENT_TYPE_       = ,    //	32～39	预留 
    // EVENT_TYPE_EMER         = 40,    //	40	应急 
    // EVENT_TYPE_INSPECT_M    = 41,    //	41	月检 
    // EVENT_TYPE_INSPECT_Y    = 42,    //	42	年检 
    // EVENT_TYPE_CHANGE_DIR   = 43,    //	43	标志灯具改变方向 
    // EVENT_TYPE_       = ,    //	44	电梯迫降 
    // EVENT_TYPE_       = ,    //	45	卷帘半降 
    // EVENT_TYPE_       = ,    //	46	卷帘全降 
    // EVENT_TYPE_       = ,    //	47	呼叫 
    // EVENT_TYPE_       = ,    //	48	通话 
    // EVENT_TYPE_       = ,    //	49	消防设备电源失电 
    // EVENT_TYPE_       = ,    //	50	消防设备电源欠压 
    // EVENT_TYPE_       = ,    //	51	消防设备电源过压 
    // EVENT_TYPE_       = ,    //	52	消防设备电源过载 
    // EVENT_TYPE_       = ,    //	53	消防设备电源缺相 
    // EVENT_TYPE_       = ,    //	54	消防设备电源错相 
    // EVENT_TYPE_       = ,    //	55	消防水箱（池）水位低 
    // EVENT_TYPE_       = ,    //	56	消防电梯停用 
    // EVENT_TYPE_       = ,    //	57～69	预留 
    EVENT_TYPE_REGULATE= 70,    //	70	监管 
    EVENT_TYPE_REGULATE_RLS = 71,    //	71	监管解除 
    EVENT_TYPE_SHIELD = 72,    //	72	屏蔽 
    EVENT_TYPE_SHIELD_RLS = 73,    //	73	屏蔽解除 
    // EVENT_TYPE_       = ,    //	74～79	预留 
    EVENT_TYPE_FAULT        = 80,    //	80	故障 
    EVENT_TYPE_FAULT_COMM   = 81,    //	81	通讯故障		应显示为：X回路 XXX号通信故障
    EVENT_TYPE_FAULT_MPWR   = 82,    //	82	主电故障 
    EVENT_TYPE_FAULT_BPWR   = 83,    //	83	备电故障 
    EVENT_TYPE_FAULT_CHRG   = 84,    //	84	充电故障 
    EVENT_TYPE_FAULT_LOOP   = 85,    //	85	回路故障 
    EVENT_TYPE_FAULT_PART   = 86,    //	86	光源故障 
    EVENT_TYPE_FAULT_PATH   = 87,    //	87	线路故障 
    // EVENT_TYPE_       = ,    //	88	接地故障 
    // EVENT_TYPE_       = ,    //	89	常闭防火门打开 
    // EVENT_TYPE_       = ,    //	90	常开防火门关闭
	EVENT_TYPE_FAULT_OUTPUT_OPEN	= 91,   //91 回路输出开路
	EVENT_TYPE_FAULT_BKP_LOWVOL 	= 92,	//92 备电欠压	当有备电故障发生，则应清除备电欠压
	// EVENT_TYPE_FAULT_SAMPLELINE		= 93,	//94 采样线故障
	// EVENT_TYPE_FAULT_OVERVOL		= 94,	//94 36V输出过压
	// EVENT_TYPE_FAULT_LOWVOL 		= 95,	//95 36V输出欠压
	// EVENT_TYPE_FAULT_FUSE_OPEN = 96,    	//96 保险丝开路
	// EVENT_TYPE_FAULT_ROUTE	= 97,			//路由故障
	// EVENT_TYPE_FAULT_COMM_ROUTE	= 98,		//通讯故障		应显示为：X路由 XXX号通信故障
    //EVENT_TYPE_      = 99,    //	99 	        应急/火警/故障手动恢复 
    EVENT_TYPE_RECOV        = 100,    			//100 	故障恢复 
    EVENT_TYPE_RECOV_COMM   = 101,    		//101 	通讯故障恢复 与81对应
    EVENT_TYPE_RECOV_MPWR   = 102,    			//102	主电故障恢复 
    EVENT_TYPE_RECOV_BPWR   = 103,    			//103	备电故障恢复 
    EVENT_TYPE_RECOV_CHRG   = 104,    			//104	充电故障恢复 
    EVENT_TYPE_RECOV_LOOP   = 105,    			//105	回路故障恢复 与85对应
    EVENT_TYPE_RECOV_PART   = 106,    			//106	光源故障恢复 
    EVENT_TYPE_RECOV_PATH   = 107,    			//107	线路故障恢复 
    // EVENT_TYPE_       = ,    //	108 	接地故障恢复 
    // EVENT_TYPE_       = ,    //	109 	常闭防火门恢复关闭状态 
    // EVENT_TYPE_       = ,    //	状态代码	说明 
    // EVENT_TYPE_       = ,    //	110 	常开防火门恢复开门状态 
	EVENT_TYPE_RECOV_OUTPUT_OPEN = 111,    		//111 回路输出开路清除(91输出开路的恢复事件)
	EVENT_TYPE_RECOV_BKP_LOWVOL = 112,//备电欠压清除 与92对应
	// EVENT_TYPE_RECOV_SAMPLELINE	= 113,			//采样线故障恢复 与93对应
	// EVENT_TYPE_RECOV_OVERVOL = 114,	//输出过压清除 与94对应
	// EVENT_TYPE_RECOV_LOWVOL = 115,	//输出欠压清除 与95对应
	// EVENT_TYPE_RECOV_FUSE_OPEN = 116,			//回路保险丝开路清除 与96对应
	// EVENT_TYPE_RECOV_ROUTE = 117,				//路由故障恢复
	// EVENT_TYPE_RECOV_COMM_ROUTE = 118,			//通信故障恢复 与98对应
    // EVENT_TYPE_       = ,    //	119	预留
    EVENT_TYPE_POWERON      = 120,    //	120 	开机 
    EVENT_TYPE_SHUTDOWN     = 121,    //	121 	关机 
    EVENT_TYPE_RESET        = 122,    //	122 	复位 
    EVENT_TYPE_SELFTEST     = 123,    //	123 	自检 
    // EVENT_TYPE_       = ,    //	124 	自检失败 
    EVENT_TYPE_STATE_MANU   = 125,    //	125 	手动状态 
    EVENT_TYPE_STATE_AUTO   = 126,    //	126 	自动状态 
    EVENT_TYPE_MUTE         = 127,    //	127 	确认/消音 
    // EVENT_TYPE_       = ,    //	128 	确认控制按钮动作 
    EVENT_TYPE_BT_CHECK     = 129,    //	129 	检查功能按钮（键）动作 
    EVENT_TYPE_SET_DATETIME = 130,    //	130 	调整时钟 
    // EVENT_TYPE_       = ,    //	131～172	预留
	EVENT_TYPE_SPRAY_FEEDBACK_RLS      = 173,  //喷洒反馈停止
	EVENT_TYPE_GAS_SPRAY_STOP          = 174,  //气体喷洒停止
    EVENT_TYPE_OP_PASSWORD_LOGIN       = 175,  //操作权限登录
    EVENT_TYPE_SETTING_PASSWORD_LOGIN  = 176,  //设置权限登录
    EVENT_TYPE_SUPER_PASSWORD_LOGIN    = 177,  //超级权限登录
    EVENT_TYPE_AREA_MANUAL  = 178,  //分区手动动作
    EVENT_TYPE_AREA_AUTO    = 179,  //分区自动动作
    EVENT_TYPE_OUTPUTLINE_FAULT       = 180,  //输出线故障
    EVENT_TYPE_OUTPUTLINE_FAULT_REC   = 181,  //输出线故障恢复
    EVENT_TYPE_INPUTLINE_FAULT       = 182,  //输入线故障
    EVENT_TYPE_INPUTLINE_FAULT_REC   = 183,  //输入线故障恢复
	// EVENT_TYPE_FORCE_EMR = 198,//强制应急操作 对应强制启动开关的操作，只写历史记录
	// EVENT_TYPE_FORCE_EMR_CANCEL = 199,//强制应急操作取消 对应强制启动开关的操作，只写历史记录 与198事件对应
    EVENT_TYPE_DEV_REG      = 200,    //	200 设备注册
    EVENT_TYPE_OP_SETTING   = 201,    //	201 设置操作
    // EVENT_TYPE_M_INSPECT_M  = 202,    //	202 手动月检
    // EVENT_TYPE_M_INSPECT_Y  = 203,    //	203 手动年检
    // EVENT_TYPE_M_INSPECT_Q  = 204,    //	204 手动季检
    // EVENT_TYPE_A_INSPECT_M  = 205,    //	205 月检时间到
    // EVENT_TYPE_A_INSPECT_Q  = 206,    //	206 季检时间到
    // EVENT_TYPE_INSPECT_Q    = 207,    //	207 季检
    // EVENT_TYPE_SELFTEST_END = 208,    //	208 系统自检结束
    // EVENT_TYPE_       = ,    //	208 预留
    EVENT_TYPE_DELAY       			= 209,    //	209 延时开始
    EVENT_TYPE_DELAY_COMPLETE       = 210,    //	210 延时到
    // EVENT_TYPE_       = ,    //	211 预留
    // EVENT_TYPE_       = ,    //	212 预留
    // EVENT_TYPE_       = ,    //	213 预留
    // EVENT_TYPE_       = ,    //	214 预留
    // EVENT_TYPE_       = ,    //	215 预留
    // EVENT_TYPE_       = ,    //	216 预留
    // EVENT_TYPE_       = ,    //	217 预留
    // EVENT_TYPE_FAULT_SUPPLY_OFF       = 218,    //	218 市电供电断电
    // EVENT_TYPE_RECOV_SUPPLY_ON       = 219,    //	219 市电供电恢复
    // EVENT_TYPE_SIM_FIRE_ALM = 220,    //	220 模拟火警
    // EVENT_TYPE_EMER_IN      = 221,    //	221 应急输入
    // EVENT_TYPE_EMER_IN_RLS  = 222,    //	222 应急输入解除
    // EVENT_TYPE_LIGHT_SCR    = 223,    //	223 灯具故障屏蔽
    // EVENT_TYPE_LIGHT_SCR_RLS= 224,    //	224 灯具故障屏蔽解除
    // EVENT_TYPE_PWR_SCR      = 225,    //	225 集中电源故障屏蔽
    // EVENT_TYPE_PWR_SCR_RLS  = 226,    //	226 集中电源故障屏蔽解除
    // EVENT_TYPE_HOST_SCR     = 227,    //	227 控制器故障屏蔽
    // EVENT_TYPE_HOST_SCR_RLS = 228,    //	228 控制器故障屏蔽解除
    EVENT_TYPE_FAULT_OVER_LOOP  = 229,    //	229 回路输出过载            // 2023-02-23
    EVENT_TYPE_RECOV_OVER_LOOP  = 230,    //	230 回路输出过载恢复    // 2022-02-23
    EVENT_TYPE_FAULT_PWR_OVER  = 231,    //	231 电源过载            // 2022-07-14
    EVENT_TYPE_RECOV_PWR_OVER  = 232,    //	232 电源过载恢复    // 2022-07-14
    EVENT_TYPE_FAULT_RS232        = 233,    //	233 RS232通信故障
    EVENT_TYPE_FAULT_RS232_RLS    = 234,    //	234 RS232通信故障恢复
    EVENT_TYPE_FAULT_CAN          = 235,    //	235 CAN通信故障 用于集中电源通信故障
    EVENT_TYPE_FAULT_CAN_RLS      = 236,    //	236 CAN通信故障恢复 用于集中电源通信故障
    // EVENT_TYPE_FAULT_EMERTIME     = 237,    //	237 应急时间故障
    // EVENT_TYPE_FAULT_EMERTIME_RLS = 238,    //	238 应急时间故障恢复
    // EVENT_TYPE_FAULT_EMER         = 239,    //	239 应急功能故障
    // EVENT_TYPE_FAULT_EMER_RLS     = 240,    //	240 应急功能故障恢复

	EVENT_TYPE_FAULT_SYSCONF      = 241,    //	241 系统设置错误
	EVENT_TYPE_FAULT_DEVCONF      = 242,    //	242 灯具设置错误
	EVENT_TYPE_FAULT_SYSCONF_RLS  = 243,    //	243 系统设置错误恢复
	EVENT_TYPE_FAULT_DEVCONF_RLS  = 244,    //	244 灯具设置错误恢复
	// EVENT_TYPE_FAULT_OVER_ROUTE = 245,// 245 路由输出过载
	// EVENT_TYPE_RECOV_OVER_ROUTE = 246,// 246 路由输出过载清除
	EVENT_TYPE_CXL_GAS_FIRE = 248,//临时用于取消分区延时事件
	EVENT_TYPE_PRE_WARNING_REC = 249,//预警事件恢复
    // EVENT_TYPE_       = ,    //	247-255 预留
    // EVENT_TYPE_LOGIN        = 256,    //	256 登陆
    // EVENT_TYPE_LOGOUT       = 257,    //	257 注销
    // EVENT_TYPE_PRJ_CREATE   = 258,    //	258 创建工程
    // EVENT_TYPE_PRJ_SAVE     = 259,    //	259 保存工程
    // EVENT_TYPE_REC_BACKUP   = 260,    //	260 记录备份
    // EVENT_TYPE_REC_CLEAR    = 261,    //	261 记录清除
    // EVENT_TYPE_LICENSE_SET  = 262,    //	262 授权设置
    // EVENT_TYPE_USER_MANAGE  = 263,    //	263 用户管理
    // EVENT_TYPE_       = ,    //	264 预留
    // EVENT_TYPE_       = ,    //	265 预留
    // EVENT_TYPE_       = ,    //	266 预留
    // EVENT_TYPE_       = ,    //	267 预留
    // EVENT_TYPE_       = ,    //	268 预留
    // EVENT_TYPE_       = ,    //	269 预留
    // EVENT_TYPE_       = ,    //	270 预留
}EVENT_TypeDef;//事件类型表
const EventDesc_t eventDescArr[] = 
{
	{EVENT_TYPE_FFIRE_ALM, 				"首火警"},
	{EVENT_TYPE_FIRE_ALM,				"火警"},
	{EVENT_TYPE_LEL_LOW_ALARM,			"低限报警"},
	{EVENT_TYPE_LEL_HIGH_ALARM,			"高限报警"},
	{EVENT_TYPE_EMR_START,				"现场急启"},	
	{EVENT_TYPE_STARTUP,				"启动"},
	{EVENT_TYPE_GAS_SPRAY,				"启动喷洒"},
	{EVENT_TYPE_FEEDBACK,				"反馈"},
	{EVENT_TYPE_SPRAY_FEEDBACK,			"喷洒反馈"},
	{EVENT_TYPE_DELAY,					"延时开始"},
	{EVENT_TYPE_FAULT,					"故障"},
	{EVENT_TYPE_FAULT_COMM,				"通讯故障"},
	{EVENT_TYPE_FAULT_MPWR,				"主电故障"},
	{EVENT_TYPE_FAULT_BPWR,				"备电故障"},
	{EVENT_TYPE_FAULT_CHRG,				"充电故障"},
	{EVENT_TYPE_FAULT_LOOP,				"回路故障"},
	{EVENT_TYPE_FAULT_PART,				"部件故障"},
	{EVENT_TYPE_FAULT_OUTPUT_OPEN,		"回路输出开路"},
	{EVENT_TYPE_FAULT_BKP_LOWVOL,		"备电欠压"},
	{EVENT_TYPE_FAULT_PWR_OVER,			"电源过载"},
	{EVENT_TYPE_FAULT_RS232,			"RS232通信故障"},
	{EVENT_TYPE_FAULT_CAN,				"CAN通信故障"},
	{EVENT_TYPE_SHIELD,					"屏蔽"},
	{EVENT_TYPE_REGULATE,				"监管"},
	{EVENT_TYPE_EMR_STOP, 				"现场急停"},
	{EVENT_TYPE_STOP,					"停止"},
	{EVENT_TYPE_GAS_SPRAY_STOP,			"喷洒停止"},
	{EVENT_TYPE_FEEDBACK_RLS,			"反馈撤销"},
	{EVENT_TYPE_SPRAY_FEEDBACK_RLS,		"喷洒反馈撤销"},	
	{EVENT_TYPE_DELAY_COMPLETE,			"延时结束"},
	{EVENT_TYPE_RECOV,					"故障恢复"},
	{EVENT_TYPE_RECOV_COMM,				"通讯故障恢复"},
	{EVENT_TYPE_RECOV_MPWR,				"主电故障恢复"},
	{EVENT_TYPE_RECOV_BPWR,				"备电故障恢复"},
	{EVENT_TYPE_RECOV_CHRG,				"充电故障恢复"},
	{EVENT_TYPE_RECOV_LOOP,				"回路故障恢复"},
	{EVENT_TYPE_RECOV_PART,				"部件故障恢复"},
	{EVENT_TYPE_RECOV_OUTPUT_OPEN,		"回路输出开路恢复"},
	{EVENT_TYPE_RECOV_BKP_LOWVOL,		"备电欠压恢复"},
	{EVENT_TYPE_RECOV_PWR_OVER,			"电源过载恢复"},
	{EVENT_TYPE_FAULT_RS232_RLS,		"RS232通信故障恢复"},
	{EVENT_TYPE_FAULT_CAN_RLS,			"CAN通信故障恢复"},
	{EVENT_TYPE_SHIELD_RLS,				"屏蔽解除"},
	{EVENT_TYPE_REGULATE_RLS,			"监管解除"},
	{(EVENT_TypeDef)0xFF,				""},
};
/*******************************************************************************
 * @description: 根据事件类型获取文字描述
 * @param {uint16_t} eventCode
 * @return {*}
 *******************************************************************************/
const char* EventList_GetTypeChar(uint16_t eventCode)
{
	uint8_t index=0;
	
	for(index=0; index<sizeof(eventDescArr)/sizeof(eventDescArr[0]); index++)
	{
		if(eventDescArr[index].eventCode == eventCode)
		{
			break;
		}
		
		if(eventDescArr[index].eventCode == 0xFF)
		{
			return "";
		}
	}
	
	return eventDescArr[index].eventString;
}	

int main()
{
	uint16_t eventCode = 0x03;
    char buffer[100];
    const char *p = EventList_GetTypeChar(eventCode);
    if(p == NULL)
    {
        return -1;
    }
    //free(p);

	printf("Event Type: %s\n", p);
	snprintf(buffer, sizeof(buffer), "Event Type: %s\n", EventList_GetTypeChar(eventCode));
    printf("%s", buffer);

	return 0;
}