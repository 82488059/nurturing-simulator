
// xy2simulatorDlg.h: 头文件
//

#pragma once
#include<vector>


// Cxy2simulatorDlg 对话框
class Cxy2simulatorDlg : public CDialogEx
{
// 构造
public:
	Cxy2simulatorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_XY2SIMULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	enum { em_max_oper=432};
	enum emShuxing{ em_xuhao, em_nianling, em_qizhi, em_neili, em_zhili, em_naili, em_mingqi
		, em_daode, em_panni, em_wanxing, em_pilao, em_jinqian, em_qigai , em_caozuo, em_shuoming, em_shuxingmax	};
	enum emShuoming{em_list2Xuhao, em_list2Caozuo, em_list2Tiaojian, em_list2Beizhu,
		em_list2Max
	};
	enum emXingdong{
		em_bandu,// 伴读		6岁直接解锁					金+30 叛逆-2
		em_zuojiawu,// 做家务		6岁直接解锁					金+10 叛逆+22 气质-1
		em_huogong,// 御膳房火工	7岁,到皇宫解锁					金+30	
		em_shuishou,// 实习水手	7岁,名气>10,到海边解锁			金+50 	
		em_shouyin,// 驿站收银	8岁,名气>30,到野外解锁			金+80 
		em_jianyao,	// 太医院煎药	9岁,道德>50,到太医院解锁		金+100
		em_yinlu,		// 给阴魂引路	10岁,名气>70,气质>70,到地府解锁	金+120
		em_xiaofan,	// 黑市小贩	12岁,叛逆>90,到黑市解锁		金+160,耐力/名气/内力-2
		em_dashou,	// 打手		13岁,内力>110,到赌场解锁		金+190,气质-1,智力/道德-3
		em_maimeng,	// 卖萌要钱	13岁(要800W大话币/1000W师门)	金+900
		em_paotang,	// 青楼跑堂	14岁,耐力>130,到青楼			金+220,气质/名气/道德-2
		// 生活
		em_guozijian,	// 国子监		6岁		疲劳-20
		em_zaijia,	// 在家休息	6岁		疲劳-20
		em_huanggong,	// 皇宫		6岁		名气+26	
		em_haibian,	// 海边		7岁		疲劳-24 	
		em_yewai,		// 野外		8岁		疲劳-28 
		em_taiyiyuan,	// 太医院		9岁		疲劳-32
		em_difu,		// 地府		10岁		疲劳-36,玩性+1,名气-1
		em_heishi,	// 黑市		12岁		疲劳-38,玩性+2,智力-2
		em_duchang,	// 赌场		13岁		疲劳-40,玩性+2,道德-2
		em_lvyou,		// 旅游		13岁		疲劳-280,游戏币-800W/师门-1000W
		em_qinglou,	// 青楼		14岁		疲劳-40,玩性+2,气质-2
		// 学习
		em_yinlv,		// 音律	直接解锁	气质+24,金-120 
		em_meishu,	// 美术	直接解锁	耐力+24,金-120 
		em_shiwen,	// 诗文	直接解锁	智力+24,金-120 
		em_wushu,		// 武术	直接解锁	内力+24,金-120 
		em_wudao,		// 舞蹈	音律30次	气质+22,耐力+2,智力+2,金-120 
		em_jianzhu,	// 建筑	美术30次	耐力+22,内力+2,智力+2,金-120 
		em_zongjiao,	// 宗教	诗文30次	智力+22,气质+2,内力+2,金-120 
		em_qishu,		// 骑术	武术30次	内力+22,耐力+2,气质+2,金-120 
		// max
		em_caozuomax,
	};
	// 每次行动后属性
	int m_shuxing[em_max_oper][em_shuxingmax];
	// 行动解锁
	int m_jiesuo[em_caozuomax];
	// 计数
	int m_jishu[em_caozuomax];

private:
	CListCtrl m_list;
	CListCtrl m_list2;
	void InitList1();
	void InitList2();
	void InitData();

public:
private:
	int m_xingdong;// 总操作次数432次12*3*(18-6)
	int m_sui;
	int m_yue;
	int m_ci;
	int m_csui;
	int m_cyue;
	int m_cci;
	int AddXingdong();
	void JiesuoShenghuo();
public:
	afx_msg void OnBnClickedBtPingjia();
private:
	int m_pingjia;
	// 初始
	int m_cqizhi;// 初始气质
	int m_cneili;// 初始内力
	int m_czhili;// 初始智力
	int m_cnaili;// 初始耐力
	int m_cmingqi;// 初始名气
	int m_cdaode;// 初始道德
	int m_cpanni;// 初始叛逆
	int m_cpilao;// 初始疲劳
	int m_cwanxing;// 初始玩性
	int m_cjinqian;// 初始金钱
	// 基础
	int m_jqizhi;// 基础气质
	int m_jneili;// 基础内力
	int m_jzhili;// 基础智力
	int m_jnaili;// 基础耐力
	int m_jmingqi;// 基础名气
	int m_jdaode;// 基础道德
	int m_jpanni;// 基础叛逆
	int m_jpilao;// 基础疲劳
	int m_jwanxing;// 基础玩性
	int m_jjinqian;// 基础金钱
	// 装备
	int m_zqizhi;// 装备气质
	int m_zneili;// 装备内力
	int m_zzhili;// 装备智力
	int m_znaili;// 装备耐力
	int m_zmingqi;// 装备名气
	int m_zdaode;// 装备道德
	int m_zpanni;// 装备叛逆
	// 合计
	int m_hqizhi;// 合计气质
	int m_hneili;// 合计内力
	int m_hzhili;// 合计智力
	int m_hnaili;// 合计耐力
	int m_hmingqi;// 合计名气
	int m_hdaode;// 合计道德
	int m_hpanni;// 合计叛逆
	// 工作
	CButton m_btGbandu;		// 伴读		6岁直接解锁					金+30 叛逆-2
	CButton m_btGzuojiawu;	// 做家务		6岁直接解锁					金+10 叛逆+22 气质-1
	CButton m_btGhuogong;	// 御膳房火工	7岁,到皇宫解锁					金+30	
	CButton m_btGshuishou;	// 实习水手	7岁,名气>10,到海边解锁			金+50 	
	CButton m_btGshouyin;	// 驿站收银	8岁,名气>30,到野外解锁			金+80 
	CButton m_btGjianyao;	// 太医院煎药	9岁,道德>50,到太医院解锁		金+100
	CButton m_btGyinlu;		// 给阴魂引路	10岁,名气>70,气质>70,到地府解锁	金+120
	CButton m_btGxiaofan;	// 黑市小贩	12岁,叛逆>90,到黑市解锁		金+160,耐力/名气/内力-2
	CButton m_btGdashou;	// 打手		13岁,内力>110,到赌场解锁		金+190,气质-1,智力/道德-3
	CButton m_btGmaimeng;	// 卖萌要钱	13岁(要800W大话币/1000W师门)	金+900
	CButton m_btGpaotang;	// 青楼跑堂	14岁,耐力>130,到青楼			金+220,气质/名气/道德-2
	// 生活
	CButton m_btSguozijian;	// 国子监		6岁		疲劳-20
	CButton m_btSzaijia;	// 在家休息	6岁		疲劳-20
	CButton m_btShuanggong;	// 皇宫		6岁		名气+26	
	CButton m_btShaibian;	// 海边		7岁		疲劳-24 	
	CButton m_btSyewai;		// 野外		8岁		疲劳-28 
	CButton m_btStaiyiyuan;	// 太医院		9岁		疲劳-32
	CButton m_btSdifu;		// 地府		10岁		疲劳-36,玩性+1,名气-1
	CButton m_btSheishi;	// 黑市		12岁		疲劳-38,玩性+2,智力-2
	CButton m_btSduchang;	// 赌场		13岁		疲劳-40,玩性+2,道德-2
	CButton m_btSlvyou;		// 旅游		13岁		疲劳-280,游戏币-800W/师门-1000W
	CButton m_btSqinglou;	// 青楼		14岁		疲劳-40,玩性+2,气质-2
	// 学习
	CButton m_btXyinlv;		// 音律	直接解锁	气质+24,金-120 
	CButton m_btXmeishu;	// 美术	直接解锁	耐力+24,金-120 
	CButton m_btXshiwen;	// 诗文	直接解锁	智力+24,金-120 
	CButton m_btXwushu;		// 武术	直接解锁	内力+24,金-120 
	CButton m_btXwudao;		// 舞蹈	音律30次	气质+22,耐力+2,智力+2,金-120 
	CButton m_btXjianzhu;	// 建筑	美术30次	耐力+22,内力+2,智力+2,金-120 
	CButton m_btXzongjiao;	// 宗教	诗文30次	智力+22,气质+2,内力+2,金-120 
	CButton m_btXqishu;		// 骑术	武术30次	内力+22,耐力+2,气质+2,金-120 

	void InitBt();
	void SetList1ItemText();
	void JiluShuxing();
	void JiluXingdong();
	void HejiShuju();
	void ChushiJichushuxing();
	void ChushiList();
	void TiaozhuanList();

public:
	afx_msg void OnBnClickedBtChushihua();
	afx_msg void OnBnClickedBtWBandu();
	afx_msg void OnBnClickedBtWJiawu();
	afx_msg void OnBnClickedBtWHuogong();
	afx_msg void OnBnClickedBtWShuishou();
	afx_msg void OnBnClickedBtWShouyin();
	afx_msg void OnBnClickedBtWJianyao();
	afx_msg void OnBnClickedBtWYinlu();
	afx_msg void OnBnClickedBtWXiaofan();
	afx_msg void OnBnClickedBtWDashou();
	afx_msg void OnBnClickedBtWMaimeng();
	afx_msg void OnBnClickedBtWPaotang();
	afx_msg void OnBnClickedBtLGuozijian();
	afx_msg void OnBnClickedBtLZaijia();
	afx_msg void OnBnClickedBtLHuanggong();
	afx_msg void OnBnClickedBtLHaibian();
	afx_msg void OnBnClickedBtLYewai();
	afx_msg void OnBnClickedBtLTaiyiyuan();
	afx_msg void OnBnClickedBtLDifu();
	afx_msg void OnBnClickedBtLHeishi();
	afx_msg void OnBnClickedBtLDuchang();
	afx_msg void OnBnClickedBtLLvyou();
	afx_msg void OnBnClickedBtLQinglou();
	afx_msg void OnBnClickedBtSYinlv();
	afx_msg void OnBnClickedBtSMeishu();
	afx_msg void OnBnClickedBtSShiwen();
	afx_msg void OnBnClickedBtSWushu();
	afx_msg void OnBnClickedBtSWudao();
	afx_msg void OnBnClickedBtSJianzhu();
	afx_msg void OnBnClickedBtSZongjiao();
	afx_msg void OnBnClickedBtSQishu();
	afx_msg void OnBnClickedBtQingling();
};
