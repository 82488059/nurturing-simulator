
// xy2simulatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "xy2simulator.h"
#include "xy2simulatorDlg.h"
#include "afxdialogex.h"
#include <algorithm>    // std::sort
#include <vector>       // std::vector


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cxy2simulatorDlg 对话框



Cxy2simulatorDlg::Cxy2simulatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_XY2SIMULATOR_DIALOG, pParent)
	, m_sui(6)
	, m_yue(0)
	, m_ci(1)
	, m_csui(6)
	, m_cyue(0)
	, m_cci(1)
	, m_xingdong(0)
	, m_pingjia(0)
	, m_cqizhi(36)// 初始气质
	, m_cneili(36)// 初始内力
	, m_czhili(36)// 初始智力
	, m_cnaili(36)// 初始耐力
	, m_cmingqi(36)// 初始名气
	, m_cdaode(36)// 初始道德
	, m_cpanni(0)// 初始叛逆
	, m_cpilao(0)// 初始疲劳
	, m_cwanxing(0)// 初始玩性
	, m_cjinqian(9800)// 初始金钱
	, m_jqizhi(36)// 基础气质
	, m_jneili(36)// 基础内力
	, m_jzhili(36)// 基础智力
	, m_jnaili(36)// 基础耐力
	, m_jmingqi(36)// 基础名气
	, m_jdaode(36)// 基础道德
	, m_jpanni(0)// 基础叛逆
	, m_jpilao(0)// 基础疲劳
	, m_jwanxing(0)// 基础玩性
	, m_jjinqian(9800)// 基础金钱
	, m_zqizhi(0)
	, m_zneili(0)
	, m_zzhili(0)
	, m_zmingqi(0)
	, m_zdaode(0)
	, m_zpanni(0)
	, m_hqizhi(0)// 合计气质
	, m_hneili(0)// 合计内力
	, m_hzhili(0)// 合计智力
	, m_hnaili(0)// 合计耐力
	, m_hmingqi(0)// 合计名气
	, m_hdaode(0)// 合计道德
	, m_hpanni(0)// 合计叛逆
	//, m_hpilao(0)// 合计疲劳
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cxy2simulatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT_SUI, m_sui);
	DDV_MinMaxInt(pDX, m_sui, 6, 17);
	DDX_Text(pDX, IDC_EDIT_YUE, m_yue);
	DDV_MinMaxInt(pDX, m_yue, 0, 11);
	DDX_Text(pDX, IDC_EDIT_CI, m_ci);
	DDV_MinMaxInt(pDX, m_ci, 1, 3);
	DDX_Text(pDX, IDC_EDIT_SUI2, m_csui);
	DDV_MinMaxInt(pDX, m_csui, 6, 17);
	DDX_Text(pDX, IDC_EDIT_YUE3, m_cyue);
	DDV_MinMaxInt(pDX, m_cyue, 0, 11);
	DDX_Text(pDX, IDC_EDIT_CI2, m_cci);
	DDV_MinMaxInt(pDX, m_cci, 1, 3);

	DDX_Text(pDX, IDC_EDIT_PINGJIA, m_pingjia);
	DDV_MinMaxInt(pDX, m_pingjia, 0, 6000);

	DDX_Text(pDX, IDC_EDIT_QIZHI2, m_zqizhi);
	DDV_MinMaxInt(pDX, m_zqizhi, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_NEILI2, m_zneili);
	DDV_MinMaxInt(pDX, m_zneili, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_ZHILI2, m_zzhili);
	DDV_MinMaxInt(pDX, m_zzhili, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_NAILI2, m_znaili);
	DDV_MinMaxInt(pDX, m_znaili, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_MINGQI2, m_zmingqi);
	DDV_MinMaxInt(pDX, m_zmingqi, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_DAODE2, m_zdaode);
	DDV_MinMaxInt(pDX, m_zdaode, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_PANNI2, m_zpanni);
	DDV_MinMaxInt(pDX, m_zpanni, 0, 1200);


	DDX_Text(pDX, IDC_EDIT_QIZHI3, m_jqizhi);
	DDV_MinMaxInt(pDX, m_jqizhi, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_NEILI3, m_jneili);
	DDV_MinMaxInt(pDX, m_jneili, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_ZHILI3, m_jzhili);
	DDV_MinMaxInt(pDX, m_jzhili, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_NAILI3, m_jnaili);
	DDV_MinMaxInt(pDX, m_jnaili, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_MINGQI3, m_jmingqi);
	DDV_MinMaxInt(pDX, m_jmingqi, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_DAODE3, m_jdaode);
	DDV_MinMaxInt(pDX, m_jdaode, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_PANNI3, m_jpanni);
	DDV_MinMaxInt(pDX, m_jpanni, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_PILAO3, m_jpilao);
	DDV_MinMaxInt(pDX, m_jpilao, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_WANXING3, m_jwanxing);
	DDV_MinMaxInt(pDX, m_jwanxing, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_JINQIAN3, m_jjinqian);
	DDV_MinMaxInt(pDX, m_jjinqian, 0, 15000);

	DDX_Text(pDX, IDC_EDIT_QIZHI4, m_cqizhi);
	DDV_MinMaxInt(pDX, m_cqizhi, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_NEILI4, m_cneili);
	DDV_MinMaxInt(pDX, m_cneili, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_ZHILI4, m_czhili);
	DDV_MinMaxInt(pDX, m_czhili, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_NAILI4, m_cnaili);
	DDV_MinMaxInt(pDX, m_cnaili, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_MINGQI4, m_cmingqi);
	DDV_MinMaxInt(pDX, m_cmingqi, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_DAODE4, m_cdaode);
	DDV_MinMaxInt(pDX, m_cdaode, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_PANNI4, m_cpanni);
	DDV_MinMaxInt(pDX, m_cpanni, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_PILAO4, m_cpilao);
	DDV_MinMaxInt(pDX, m_cpilao, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_WANXING4, m_cwanxing);
	DDV_MinMaxInt(pDX, m_cwanxing, 0, 1200);
	DDX_Text(pDX, IDC_EDIT_JINQIAN4, m_cjinqian);
	DDV_MinMaxInt(pDX, m_cjinqian, 0, 15000);

	DDX_Text(pDX, IDC_EDIT_QIZHI, m_hqizhi);
	DDX_Text(pDX, IDC_EDIT_NEILI, m_hneili);
	DDX_Text(pDX, IDC_EDIT_ZHILI, m_hzhili);
	DDX_Text(pDX, IDC_EDIT_NAILI, m_hnaili);
	DDX_Text(pDX, IDC_EDIT_MINGQI, m_hmingqi);
	DDX_Text(pDX, IDC_EDIT_DAODE, m_hdaode);
	DDX_Text(pDX, IDC_EDIT_PANNI, m_hpanni);
	//DDX_Text(pDX, IDC_EDIT_PILAO, m_hpilao);
	//DDX_Text(pDX, IDC_EDIT_WANXING, m_hwanxing);

	DDX_Control(pDX, IDC_BT_W_BANDU, m_btGbandu);
	DDX_Control(pDX, IDC_BT_W_JIAWU, m_btGzuojiawu);
	DDX_Control(pDX, IDC_BT_W_HUOGONG, m_btGhuogong);
	DDX_Control(pDX, IDC_BT_W_SHUISHOU, m_btGshuishou);
	DDX_Control(pDX, IDC_BT_W_SHOUYIN, m_btGshouyin);
	DDX_Control(pDX, IDC_BT_W_JIANYAO, m_btGjianyao);
	DDX_Control(pDX, IDC_BT_W_YINLU, m_btGyinlu);
	DDX_Control(pDX, IDC_BT_W_XIAOFAN, m_btGxiaofan);
	DDX_Control(pDX, IDC_BT_W_DASHOU, m_btGdashou);
	DDX_Control(pDX, IDC_BT_W_MAIMENG, m_btGmaimeng);
	DDX_Control(pDX, IDC_BT_W_PAOTANG, m_btGpaotang);

	DDX_Control(pDX, IDC_BT_L_GUOZIJIAN, m_btSguozijian);
	DDX_Control(pDX, IDC_BT_L_ZAIJIA, m_btSzaijia);
	DDX_Control(pDX, IDC_BT_L_HUANGGONG, m_btShuanggong);
	DDX_Control(pDX, IDC_BT_L_HAIBIAN, m_btShaibian);
	DDX_Control(pDX, IDC_BT_L_YEWAI, m_btSyewai);
	DDX_Control(pDX, IDC_BT_L_TAIYIYUAN, m_btStaiyiyuan);
	DDX_Control(pDX, IDC_BT_L_DIFU, m_btSdifu);
	DDX_Control(pDX, IDC_BT_L_HEISHI, m_btSheishi);
	DDX_Control(pDX, IDC_BT_L_DUCHANG, m_btSduchang);
	DDX_Control(pDX, IDC_BT_L_LVYOU, m_btSlvyou);
	DDX_Control(pDX, IDC_BT_L_QINGLOU, m_btSqinglou);

	DDX_Control(pDX, IDC_BT_S_YINLV, m_btXyinlv);
	DDX_Control(pDX, IDC_BT_S_MEISHU, m_btXmeishu);
	DDX_Control(pDX, IDC_BT_S_SHIWEN, m_btXshiwen);
	DDX_Control(pDX, IDC_BT_S_WUSHU, m_btXwushu);
	DDX_Control(pDX, IDC_BT_S_WUDAO, m_btXwudao);
	DDX_Control(pDX, IDC_BT_S_JIANZHU, m_btXjianzhu);
	DDX_Control(pDX, IDC_BT_S_ZONGJIAO, m_btXzongjiao);
	DDX_Control(pDX, IDC_BT_S_QISHU, m_btXqishu);

	DDX_Text(pDX, IDC_EDIT_BANDU, m_jishu[em_bandu]);
	DDX_Text(pDX, IDC_EDIT_ZUOJIAWU, m_jishu[em_zuojiawu]);
	DDX_Text(pDX, IDC_EDIT_HUOGONG, m_jishu[em_huogong]);
	DDX_Text(pDX, IDC_EDIT_SHUISHOU, m_jishu[em_shuishou]);
	DDX_Text(pDX, IDC_EDIT_SHOUYIN, m_jishu[em_shouyin]);
	DDX_Text(pDX, IDC_EDIT_JIANYAO, m_jishu[em_jianyao]);
	DDX_Text(pDX, IDC_EDIT_YINLU, m_jishu[em_yinlu]);
	DDX_Text(pDX, IDC_EDIT_XIAOFAN, m_jishu[em_xiaofan]);
	DDX_Text(pDX, IDC_EDIT_DASHOU, m_jishu[em_dashou]);
	DDX_Text(pDX, IDC_EDIT_MAIMENG, m_jishu[em_maimeng]);
	DDX_Text(pDX, IDC_EDIT_PAOTANG, m_jishu[em_paotang]);

	DDX_Text(pDX, IDC_EDIT_GUOZIJIAN, m_jishu[em_guozijian]);
	DDX_Text(pDX, IDC_EDIT_XIUXI, m_jishu[em_zaijia]);
	DDX_Text(pDX, IDC_EDIT_HUANGGONG, m_jishu[em_huanggong]);
	DDX_Text(pDX, IDC_EDIT_HAIBIAN, m_jishu[em_haibian]);
	DDX_Text(pDX, IDC_EDIT_YEWAI, m_jishu[em_yewai]);
	DDX_Text(pDX, IDC_EDIT_TAIYIYUAN, m_jishu[em_taiyiyuan]);
	DDX_Text(pDX, IDC_EDIT_DIFU, m_jishu[em_difu]);
	DDX_Text(pDX, IDC_EDIT_HEISHI, m_jishu[em_heishi]);
	DDX_Text(pDX, IDC_EDIT_DUCHANG, m_jishu[em_duchang]);
	DDX_Text(pDX, IDC_EDIT_LVYOU, m_jishu[em_lvyou]);
	DDX_Text(pDX, IDC_EDIT_QINGLOU, m_jishu[em_qinglou]);

	DDX_Text(pDX, IDC_EDIT_YINLV, m_jishu[em_yinlv]);
	DDX_Text(pDX, IDC_EDIT_MEISHU, m_jishu[em_meishu]);
	DDX_Text(pDX, IDC_EDIT_SHIWEN, m_jishu[em_shiwen]);
	DDX_Text(pDX, IDC_EDIT_WUSHU, m_jishu[em_wushu]);
	DDX_Text(pDX, IDC_EDIT_WUDAO, m_jishu[em_wudao]);
	DDX_Text(pDX, IDC_EDIT_JIANZHU, m_jishu[em_jianzhu]);
	DDX_Text(pDX, IDC_EDIT_ZONGJIAO, m_jishu[em_zongjiao]);
	DDX_Text(pDX, IDC_EDIT_QISHU, m_jishu[em_qishu]);
}

BEGIN_MESSAGE_MAP(Cxy2simulatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BT_PINGJIA, &Cxy2simulatorDlg::OnBnClickedBtPingjia)
	ON_BN_CLICKED(IDC_BT_CHUSHIHUA, &Cxy2simulatorDlg::OnBnClickedBtChushihua)
	ON_BN_CLICKED(IDC_BT_W_BANDU, &Cxy2simulatorDlg::OnBnClickedBtWBandu)
	ON_BN_CLICKED(IDC_BT_W_JIAWU, &Cxy2simulatorDlg::OnBnClickedBtWJiawu)
	ON_BN_CLICKED(IDC_BT_W_HUOGONG, &Cxy2simulatorDlg::OnBnClickedBtWHuogong)
	ON_BN_CLICKED(IDC_BT_W_SHUISHOU, &Cxy2simulatorDlg::OnBnClickedBtWShuishou)
	ON_BN_CLICKED(IDC_BT_W_SHOUYIN, &Cxy2simulatorDlg::OnBnClickedBtWShouyin)
	ON_BN_CLICKED(IDC_BT_W_JIANYAO, &Cxy2simulatorDlg::OnBnClickedBtWJianyao)
	ON_BN_CLICKED(IDC_BT_W_YINLU, &Cxy2simulatorDlg::OnBnClickedBtWYinlu)
	ON_BN_CLICKED(IDC_BT_W_XIAOFAN, &Cxy2simulatorDlg::OnBnClickedBtWXiaofan)
	ON_BN_CLICKED(IDC_BT_W_DASHOU, &Cxy2simulatorDlg::OnBnClickedBtWDashou)
	ON_BN_CLICKED(IDC_BT_W_MAIMENG, &Cxy2simulatorDlg::OnBnClickedBtWMaimeng)
	ON_BN_CLICKED(IDC_BT_W_PAOTANG, &Cxy2simulatorDlg::OnBnClickedBtWPaotang)
	ON_BN_CLICKED(IDC_BT_L_GUOZIJIAN, &Cxy2simulatorDlg::OnBnClickedBtLGuozijian)
	ON_BN_CLICKED(IDC_BT_L_ZAIJIA, &Cxy2simulatorDlg::OnBnClickedBtLZaijia)
	ON_BN_CLICKED(IDC_BT_L_HUANGGONG, &Cxy2simulatorDlg::OnBnClickedBtLHuanggong)
	ON_BN_CLICKED(IDC_BT_L_HAIBIAN, &Cxy2simulatorDlg::OnBnClickedBtLHaibian)
	ON_BN_CLICKED(IDC_BT_L_YEWAI, &Cxy2simulatorDlg::OnBnClickedBtLYewai)
	ON_BN_CLICKED(IDC_BT_L_TAIYIYUAN, &Cxy2simulatorDlg::OnBnClickedBtLTaiyiyuan)
	ON_BN_CLICKED(IDC_BT_L_DIFU, &Cxy2simulatorDlg::OnBnClickedBtLDifu)
	ON_BN_CLICKED(IDC_BT_L_HEISHI, &Cxy2simulatorDlg::OnBnClickedBtLHeishi)
	ON_BN_CLICKED(IDC_BT_L_DUCHANG, &Cxy2simulatorDlg::OnBnClickedBtLDuchang)
	ON_BN_CLICKED(IDC_BT_L_LVYOU, &Cxy2simulatorDlg::OnBnClickedBtLLvyou)
	ON_BN_CLICKED(IDC_BT_L_QINGLOU, &Cxy2simulatorDlg::OnBnClickedBtLQinglou)
	ON_BN_CLICKED(IDC_BT_S_YINLV, &Cxy2simulatorDlg::OnBnClickedBtSYinlv)
	ON_BN_CLICKED(IDC_BT_S_MEISHU, &Cxy2simulatorDlg::OnBnClickedBtSMeishu)
	ON_BN_CLICKED(IDC_BT_S_SHIWEN, &Cxy2simulatorDlg::OnBnClickedBtSShiwen)
	ON_BN_CLICKED(IDC_BT_S_WUSHU, &Cxy2simulatorDlg::OnBnClickedBtSWushu)
	ON_BN_CLICKED(IDC_BT_S_WUDAO, &Cxy2simulatorDlg::OnBnClickedBtSWudao)
	ON_BN_CLICKED(IDC_BT_S_JIANZHU, &Cxy2simulatorDlg::OnBnClickedBtSJianzhu)
	ON_BN_CLICKED(IDC_BT_S_ZONGJIAO, &Cxy2simulatorDlg::OnBnClickedBtSZongjiao)
	ON_BN_CLICKED(IDC_BT_S_QISHU, &Cxy2simulatorDlg::OnBnClickedBtSQishu)
	ON_BN_CLICKED(IDC_BT_QINGLING, &Cxy2simulatorDlg::OnBnClickedBtQingling)
END_MESSAGE_MAP()


// Cxy2simulatorDlg 消息处理程序

BOOL Cxy2simulatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	InitList1();
	InitBt();
	// 每次行动后属性
	// m_shuxing[em_max_oper][em_shuxingmax];
	memset(m_shuxing, 0, sizeof(m_shuxing));
	// 行动解锁
	//m_jiesuo[em_caozuomax];
	memset(m_jiesuo, 0, sizeof(m_jiesuo));
	// 行动计数
	//m_jishu[em_caozuomax];
	memset(m_jishu, 0, sizeof(m_jishu));
	// 合计数据
	HejiShuju();

	UpdateData(FALSE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cxy2simulatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cxy2simulatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cxy2simulatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Cxy2simulatorDlg::InitList1()
{
	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;// 选中某行使整行高亮（仅仅适用与report 风格的listctrl ） 
	dwStyle |= LVS_EX_GRIDLINES;// 网格线（仅仅适用与report 风格的listctrl ） 
	//dwStyle |= LVS_EX_CHECKBOXES;//item 前生成checkbox 控件 
	m_list.SetExtendedStyle(dwStyle); // 设置扩展风格 
	//设置列表控件的报表显示方式
	//m_list.ModifyStyle(LVS_ICON | LVS_SMALLICON | LVS_LIST, LVS_REPORT);
	//在列表控件中插入列
	m_list.InsertColumn(em_xuhao, _T("序号"), LVCFMT_CENTER, 0);
	m_list.InsertColumn(em_nianling, _T("年龄"), LVCFMT_CENTER, 80);
	m_list.InsertColumn(em_qizhi, _T("气质"), LVCFMT_CENTER, 50);
	m_list.InsertColumn(em_neili, _T("内力"), LVCFMT_CENTER, 50);
	m_list.InsertColumn(em_zhili, _T("智力"), LVCFMT_CENTER, 50);
	m_list.InsertColumn(em_naili, _T("耐力"), LVCFMT_CENTER, 50);
	m_list.InsertColumn(em_mingqi, _T("名气"), LVCFMT_CENTER, 50);
	m_list.InsertColumn(em_daode, _T("道德"), LVCFMT_CENTER, 50);
	m_list.InsertColumn(em_panni, _T("叛逆"), LVCFMT_CENTER, 50);
	m_list.InsertColumn(em_wanxing, _T("玩性"), LVCFMT_CENTER, 50);
	m_list.InsertColumn(em_pilao, _T("疲劳"), LVCFMT_CENTER, 50);
	m_list.InsertColumn(em_jinqian, _T("金钱"), LVCFMT_CENTER, 50);
	m_list.InsertColumn(em_qigai, _T("乞丐"), LVCFMT_CENTER, 50);
	m_list.InsertColumn(em_caozuo, _T("操作"), LVCFMT_CENTER, 80);

	int ny = 6;
	int nm = 0;
	for (int m = 0; m < em_max_oper; m++)
	{
		ny = 6 + m / 36;
		nm = (m % 36) / 3;
		CString s;
		s.Format(_T("%d岁%d个月"), ny, nm);
		m_list.InsertItem(m, _T(""));
		m_list.SetItemText(m, em_nianling, s);
		s.Format(_T("%d"), m+1);
		m_list.SetItemText(m, em_xuhao, s);
	}
}

void Cxy2simulatorDlg::InitData()
{

}


int Cxy2simulatorDlg::AddXingdong()
{
	m_xingdong += 1;
	m_sui = 6 + m_xingdong / 36;
	m_yue = (m_xingdong % 36) / 3;
	m_ci = (m_xingdong % 3) + 1;
	JiesuoShenghuo();
	return 0;
}

void Cxy2simulatorDlg::JiesuoShenghuo()
{
	if (0 == m_xingdong % 36)
	{
		// 解锁
		if (0 == m_jiesuo[em_haibian] && m_sui >= 7)
		{
			m_jiesuo[em_haibian] = m_xingdong;
			m_btShaibian.EnableWindow(TRUE);
		}
		else if (0 == m_jiesuo[em_yewai] && m_sui >= 8)
		{
			m_jiesuo[em_yewai] = m_xingdong;
			m_btSyewai.EnableWindow(TRUE);
		}
		else if (0 == m_jiesuo[em_taiyiyuan] && m_sui >= 9)
		{
			m_jiesuo[em_taiyiyuan] = m_xingdong;
			m_btStaiyiyuan.EnableWindow(TRUE);
		}
		else if (0 == m_jiesuo[em_difu] && m_sui >= 10)
		{
			m_jiesuo[em_difu] = m_xingdong;
			m_btSdifu.EnableWindow(TRUE);
		}
		else if (0 == m_jiesuo[em_heishi] && m_sui >= 12)
		{
			m_jiesuo[em_heishi] = m_xingdong;
			m_btSheishi.EnableWindow(TRUE);
		}
		else if (0 == m_jiesuo[em_duchang] && m_sui >= 13)
		{
			m_jiesuo[em_duchang] = m_xingdong;
			m_btSduchang.EnableWindow(TRUE);
		}
		else if (0 == m_jiesuo[em_lvyou] && m_sui >= 13)
		{
			m_jiesuo[em_lvyou] = m_xingdong;
			m_btSlvyou.EnableWindow(TRUE);
		}
		else if (0 == m_jiesuo[em_maimeng] && m_sui >= 13)
		{
			m_jiesuo[em_maimeng] = m_xingdong;
			m_btGmaimeng.EnableWindow(TRUE);
		}
		else if (0 == m_jiesuo[em_qinglou] && m_sui >= 14)
		{
			m_jiesuo[em_qinglou] = m_xingdong;
			m_btSqinglou.EnableWindow(TRUE);
		}
	}
}

void Cxy2simulatorDlg::OnBnClickedBtPingjia()
{
	// TODO: 在此添加控件通知处理程序代码
	int arr[7];
	arr[0] = m_hqizhi;
	arr[1] = m_hneili;
	arr[2] = m_hzhili;
	arr[3] = m_hnaili;
	arr[4] = m_hmingqi;
	arr[5] = m_hdaode;
	arr[6] = m_hpanni;
	std::sort(arr, arr + 7, std::greater<int>());

	double  pingjia = 600 * pow(arr[0], 0.2) + 180 * pow(arr[1], 0.2) + 150 * pow(arr[2], 0.2) 
		+ 120 * pow(arr[3], 0.2) + 90 * pow(arr[4], 0.2) + 60 * pow(arr[5], 0.2) + 30 * pow(arr[6], 0.2);
	m_pingjia = pingjia;

	UpdateData(FALSE);
}


void Cxy2simulatorDlg::InitBt()
{
	// 工作
	m_btGbandu;		// 伴读		6岁直接解锁					金+30 叛逆-2
	m_btGzuojiawu;	// 做家务		6岁直接解锁					金+10 叛逆+22 气质-1
	m_btGhuogong.EnableWindow(FALSE);	// 御膳房火工	7岁,到皇宫解锁					金+30	
	m_btGshuishou.EnableWindow(FALSE);	// 实习水手	7岁,名气>10,到海边解锁			金+50 	
	m_btGshouyin.EnableWindow(FALSE);	// 驿站收银	8岁,名气>30,到野外解锁			金+80 
	m_btGjianyao.EnableWindow(FALSE);	// 太医院煎药	9岁,道德>50,到太医院解锁		金+100
	m_btGyinlu.EnableWindow(FALSE);		// 给阴魂引路	10岁,名气>70,气质>70,到地府解锁	金+120
	m_btGxiaofan.EnableWindow(FALSE);	// 黑市小贩	12岁,叛逆>90,到黑市解锁		金+160,耐力/名气/内力-2
	m_btGdashou.EnableWindow(FALSE);	// 打手		13岁,内力>110,到赌场解锁		金+190,气质-1,智力/道德-3
	m_btGmaimeng.EnableWindow(FALSE);	// 卖萌要钱	13岁(要800W大话币/1000W师门)	金+900
	m_btGpaotang.EnableWindow(FALSE);	// 青楼跑堂	14岁,耐力>130,到青楼			金+220,气质/名气/道德-2
	// 生活
	m_btSguozijian;	// 国子监		6岁		疲劳-20
	m_btSzaijia;	// 在家休息	6岁		疲劳-20
	m_btShuanggong;	// 皇宫		6岁		名气+26	
	m_btShaibian.EnableWindow(FALSE);	// 海边		7岁		疲劳-24 	
	m_btSyewai.EnableWindow(FALSE);		// 野外		8岁		疲劳-28 
	m_btStaiyiyuan.EnableWindow(FALSE);	// 太医院		9岁		疲劳-32
	m_btSdifu.EnableWindow(FALSE);		// 地府		10岁		疲劳-36,玩性+1,名气-1
	m_btSheishi.EnableWindow(FALSE);	// 黑市		12岁		疲劳-38,玩性+2,智力-2
	m_btSduchang.EnableWindow(FALSE);	// 赌场		13岁		疲劳-40,玩性+2,道德-2
	m_btSlvyou.EnableWindow(FALSE);		// 旅游		13岁		疲劳-280,游戏币-800W/师门-1000W
	m_btSqinglou.EnableWindow(FALSE);	// 青楼		14岁		疲劳-40,玩性+2,气质-2

	// 学习
	m_btXyinlv;		// 音律	直接解锁	气质+24,金-120 
	m_btXmeishu;	// 美术	直接解锁	耐力+24,金-120 
	m_btXshiwen;	// 诗文	直接解锁	智力+24,金-120 
	m_btXwushu;		// 武术	直接解锁	内力+24,金-120 

	m_btXwudao.EnableWindow(FALSE);		// 舞蹈	音律30次	气质+22,耐力+2,智力+2,金-120 
	m_btXjianzhu.EnableWindow(FALSE);	// 建筑	美术30次	耐力+22,内力+2,智力+2,金-120 
	m_btXzongjiao.EnableWindow(FALSE);	// 宗教	诗文30次	智力+22,气质+2,内力+2,金-120 
	m_btXqishu.EnableWindow(FALSE);		// 骑术	武术30次	内力+22,耐力+2,气质+2,金-120 

}

void Cxy2simulatorDlg::SetList1ItemText()
{
	CString szText;
	szText.Format(_T("%d"), m_jqizhi);
	m_list.SetItemText(m_xingdong, em_qizhi, szText);
	szText.Format(_T("%d"), m_jneili);
	m_list.SetItemText(m_xingdong, em_neili, szText);
	szText.Format(_T("%d"), m_jzhili);
	m_list.SetItemText(m_xingdong, em_zhili, szText);
	szText.Format(_T("%d"), m_jnaili);
	m_list.SetItemText(m_xingdong, em_naili, szText);
	szText.Format(_T("%d"), m_jmingqi);
	m_list.SetItemText(m_xingdong, em_mingqi, szText);
	szText.Format(_T("%d"), m_jdaode);
	m_list.SetItemText(m_xingdong, em_daode, szText);
	szText.Format(_T("%d"), m_jpanni);
	m_list.SetItemText(m_xingdong, em_panni, szText);
	szText.Format(_T("%d"), m_jwanxing);
	m_list.SetItemText(m_xingdong, em_wanxing, szText);
	szText.Format(_T("%d"), m_jpilao);
	m_list.SetItemText(m_xingdong, em_pilao, szText);
	szText.Format(_T("%d"), m_jjinqian);
	m_list.SetItemText(m_xingdong, em_jinqian, szText);
}

void Cxy2simulatorDlg::JiluShuxing()
{
	m_shuxing[m_xingdong][em_xuhao] = m_xingdong;//
	m_shuxing[m_xingdong][em_qizhi] = m_jqizhi;// 基础气质
	m_shuxing[m_xingdong][em_neili] = m_jneili;// 基础内力
	m_shuxing[m_xingdong][em_zhili] = m_jzhili;// 基础智力
	m_shuxing[m_xingdong][em_naili] = m_jnaili;// 基础耐力
	m_shuxing[m_xingdong][em_mingqi] = m_jmingqi;// 基础名气
	m_shuxing[m_xingdong][em_daode] = m_jdaode;// 基础道德
	m_shuxing[m_xingdong][em_panni] = m_jpanni;// 基础叛逆
	m_shuxing[m_xingdong][em_pilao] = m_jpilao;// 基础疲劳
	m_shuxing[m_xingdong][em_wanxing] = m_jwanxing;// 基础玩性
	m_shuxing[m_xingdong][em_jinqian] = m_jjinqian;// 基础金钱

	m_hqizhi = m_zqizhi + m_jqizhi;// 合计气质
	m_hneili = m_zneili + m_jneili;// 合计内力
	m_hzhili = m_zzhili + m_jzhili;// 合计智力
	m_hnaili = m_znaili + m_jnaili;// 合计耐力
	m_hmingqi = m_zmingqi + m_jmingqi;// 合计名气
	m_hdaode = m_zdaode + m_jdaode;// 合计道德
	m_hpanni = m_zpanni + m_jpanni;// 合计叛逆
	//m_hpilao = m_jpilao;// 合计疲劳
	//m_hwanxing = m_jwanxing;// 合计玩性
}

void Cxy2simulatorDlg::JiluXingdong()
{
	CString szText;
	szText.Format(_T("%d"), m_jqizhi);
	m_list.SetItemText(m_xingdong, em_qizhi, szText);
	szText.Format(_T("%d"), m_jneili);
	m_list.SetItemText(m_xingdong, em_neili, szText);
	szText.Format(_T("%d"), m_jzhili);
	m_list.SetItemText(m_xingdong, em_zhili, szText);
	szText.Format(_T("%d"), m_jnaili);
	m_list.SetItemText(m_xingdong, em_naili, szText);
	szText.Format(_T("%d"), m_jmingqi);
	m_list.SetItemText(m_xingdong, em_mingqi, szText);
	szText.Format(_T("%d"), m_jdaode);
	m_list.SetItemText(m_xingdong, em_daode, szText);
	szText.Format(_T("%d"), m_jpanni);
	m_list.SetItemText(m_xingdong, em_panni, szText);
	szText.Format(_T("%d"), m_jwanxing);
	m_list.SetItemText(m_xingdong, em_wanxing, szText);
	szText.Format(_T("%d"), m_jpilao);
	m_list.SetItemText(m_xingdong, em_pilao, szText);
	szText.Format(_T("%d"), m_jjinqian);
	m_list.SetItemText(m_xingdong, em_jinqian, szText);
}

void Cxy2simulatorDlg::HejiShuju()
{
	m_hqizhi = m_zqizhi + m_jqizhi;// 合计气质
	m_hneili = m_zneili + m_jneili;// 合计内力
	m_hzhili = m_zzhili + m_jzhili;// 合计智力
	m_hnaili = m_znaili + m_jnaili;// 合计耐力
	m_hmingqi = m_zmingqi + m_jmingqi;// 合计名气
	m_hdaode = m_zdaode + m_jdaode;// 合计道德
	m_hpanni = m_zpanni + m_jpanni;// 合计叛逆
}

void Cxy2simulatorDlg::ChushiJichushuxing()
{
	if (m_cci > 3)
		m_cci = 3;
	if (m_cci < 1)
		m_cci = 1;
	if (m_cyue > 11)
		m_cyue = 11;
	if (m_cyue < 0)
		m_cyue = 0;
	if (m_csui > 17)
		m_csui = 17;
	if (m_csui < 6)
		m_csui = 6;
	if (m_cqizhi > 1200)
		m_cqizhi = 1200;
	if (m_cqizhi < 0)
		m_cqizhi = 0;
	if (m_cneili > 1200)
		m_cneili = 1200;
	if (m_cneili < 0)
		m_cneili = 0;
	if (m_czhili > 1200)
		m_czhili = 1200;
	if (m_czhili < 0)
		m_czhili = 0;
	if (m_cnaili > 1200)
		m_cnaili = 1200;
	if (m_cnaili < 0)
		m_cnaili = 0;
	if (m_cmingqi > 1200)
		m_cmingqi = 1200;
	if (m_cmingqi < 0)
		m_cmingqi = 0;
	if (m_cdaode > 1200)
		m_cdaode = 1200;
	if (m_cdaode < 0)
		m_cdaode = 0;
	if (m_cpanni > 1200)
		m_cpanni = 1200;
	if (m_cpanni < 0)
		m_cpanni = 0;
	if (m_cpilao > 1200)
		m_cpilao = 1200;
	if (m_cpilao < 0)
		m_cpilao = 0;
	if (m_cwanxing > 1200)
		m_cwanxing = 1200;
	if (m_cwanxing < 0)
		m_cwanxing = 0;
	if (m_cjinqian > 15000)
		m_cjinqian = 15000;
	if (m_cjinqian < 0)
		m_cjinqian = 0;

	m_jqizhi = m_cqizhi;// 基础气质
	m_jneili = m_cneili;// 基础内力
	m_jzhili = m_czhili;// 基础智力
	m_jnaili = m_cnaili;// 基础耐力
	m_jmingqi = m_cmingqi;// 基础名气
	m_jdaode = m_cdaode;// 基础道德
	m_jpanni = m_cpanni;// 基础叛逆
	m_jpilao = m_cpilao;// 基础疲劳
	m_jwanxing = m_cwanxing;// 基础玩性
	m_jjinqian = m_cjinqian;// 基础金钱

	m_yue = m_cyue;
	m_sui = m_csui;
	m_ci = m_cci;
	m_xingdong = (m_csui - 6) * 36 + m_cyue * 3 + m_cci - 1;
}

void Cxy2simulatorDlg::ChushiList()
{
	for (int i = 0; i < em_max_oper; i++)
	{
		if (i+1 == m_xingdong)
		{
			CString szText;
			szText.Format(_T("%d"), m_jqizhi);
			m_list.SetItemText(i, em_qizhi, szText);
			szText.Format(_T("%d"), m_jneili);
			m_list.SetItemText(i, em_neili, szText);
			szText.Format(_T("%d"), m_jzhili);
			m_list.SetItemText(i, em_zhili, szText);
			szText.Format(_T("%d"), m_jnaili);
			m_list.SetItemText(i, em_naili, szText);
			szText.Format(_T("%d"), m_jmingqi);
			m_list.SetItemText(i, em_mingqi, szText);
			szText.Format(_T("%d"), m_jdaode);
			m_list.SetItemText(i, em_daode, szText);
			szText.Format(_T("%d"), m_jpanni);
			m_list.SetItemText(i, em_panni, szText);
			szText.Format(_T("%d"), m_jwanxing);
			m_list.SetItemText(i, em_wanxing, szText);
			szText.Format(_T("%d"), m_jpilao);
			m_list.SetItemText(i, em_pilao, szText);
			szText.Format(_T("%d"), m_jjinqian);
			m_list.SetItemText(i, em_jinqian, szText);
			m_list.SetItemText(i, em_caozuo, szText);
		}
		else
		{
			CString szText(_T(""));
			m_list.SetItemText(i, em_qizhi, szText);
			m_list.SetItemText(i, em_neili, szText);
			m_list.SetItemText(i, em_zhili, szText);
			m_list.SetItemText(i, em_naili, szText);
			m_list.SetItemText(i, em_mingqi, szText);
			m_list.SetItemText(i, em_daode, szText);
			m_list.SetItemText(i, em_panni, szText);
			m_list.SetItemText(i, em_wanxing, szText);
			m_list.SetItemText(i, em_pilao, szText);
			m_list.SetItemText(i, em_jinqian, szText);
			m_list.SetItemText(i, em_caozuo, szText);

		}

	}
}

void Cxy2simulatorDlg::TiaozhuanList()
{
	m_list.SetItemState(m_xingdong, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
	m_list.EnsureVisible(m_xingdong, FALSE);
}

void Cxy2simulatorDlg::OnBnClickedBtChushihua()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	
	ChushiJichushuxing();

	ChushiList();

	HejiShuju();

	TiaozhuanList();

	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtWBandu()
{
	// TODO: 在此添加控件通知处理程序代码
	// 伴读		6岁直接解锁					金+30 叛逆-2
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	if (m_jpilao >= 300)
		return;
	m_jpilao += 18;
	m_jjinqian += 30;
	if (m_jjinqian > 15000)
		m_jjinqian = 15000;
	m_jpanni -= 2;
	if (m_jpanni < 0)
		m_jpanni = 0;
	
	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("伴读"));
	m_shuxing[m_xingdong][em_caozuo] = em_bandu;
	m_jishu[em_bandu]++;

	TiaozhuanList();
	AddXingdong();

	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtWJiawu()
{
	// TODO: 在此添加控件通知处理程序代码
	// 做家务		6岁直接解锁					金+10 叛逆+22 气质-1
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	if (m_jpilao >= 300)
		return;
	m_jpilao += 18;
	m_jjinqian += 10;
	m_jpanni += 22;
	if (m_jpanni > 1200)
		m_jpanni = 1200;
	m_jqizhi -= 1;
	if (m_jqizhi < 0)
		m_jqizhi = 0;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("做家务"));
	m_shuxing[m_xingdong][em_caozuo] = em_zuojiawu;
	m_jishu[em_zuojiawu]++;
	
	TiaozhuanList();
	AddXingdong();
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtWHuogong()
{
	// TODO: 在此添加控件通知处理程序代码
	// 御膳房火工	7岁,到皇宫解锁					金+30	
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	if (m_jpilao >= 300)
		return;
	m_jpilao += 18;
	m_jjinqian += 30;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("御膳房火工"));
	m_shuxing[m_xingdong][em_caozuo] = em_huogong;
	m_jishu[em_huogong]++;

	TiaozhuanList();
	AddXingdong();
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtWShuishou()
{
	// TODO: 在此添加控件通知处理程序代码
	// 实习水手	7岁,名气>10,到海边解锁			金+50 
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	if (m_jpilao >= 300)
		return;
	m_jpilao += 18;
	m_jjinqian += 50;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("实习水手"));
	m_shuxing[m_xingdong][em_caozuo] = em_shuishou;
	m_jishu[em_shuishou]++;

	TiaozhuanList();
	AddXingdong();
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtWShouyin()
{
	// TODO: 在此添加控件通知处理程序代码	
	// 驿站收银	8岁,名气>30,到野外解锁			金+80 
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	if (m_jpilao >= 300)
		return;
	m_jpilao += 18;
	m_jjinqian += 80;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("驿站收银"));
	m_shuxing[m_xingdong][em_caozuo] = em_shouyin;
	m_jishu[em_shouyin]++;

	TiaozhuanList();
	AddXingdong();
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtWJianyao()
{
	// TODO: 在此添加控件通知处理程序代码
	// 太医院煎药	9岁,道德>50,到太医院解锁		金+100
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	if (m_jpilao >= 300)
		return;
	m_jpilao += 18;
	m_jjinqian += 100;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("太医院煎药"));
	m_shuxing[m_xingdong][em_caozuo] = em_jianyao;
	m_jishu[em_jianyao]++;

	TiaozhuanList();
	AddXingdong();
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtWYinlu()
{
	// TODO: 在此添加控件通知处理程序代码
	// 给阴魂引路	10岁,名气>70,气质>70,到地府解锁	金+120
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	if (m_jpilao >= 300)
		return;
	m_jpilao += 18;
	m_jjinqian += 120;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("给阴魂引路"));
	m_shuxing[m_xingdong][em_caozuo] = em_yinlu;
	m_jishu[em_yinlu]++;

	TiaozhuanList();
	AddXingdong();
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtWXiaofan()
{
	// TODO: 在此添加控件通知处理程序代码
	// 黑市小贩	12岁,叛逆>90,到黑市解锁		金+160,耐力/名气/内力-2
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	if (m_jpilao >= 300)
		return;
	m_jpilao += 18;
	m_jjinqian += 160;

	int n = rand() % 3;
	if (0 == n)	{
		m_jnaili -= 2;
		if (m_jnaili < 0)		{
			m_jnaili = 0;
		}
	}	else if(1==n)	{
		m_jmingqi -= 2;
		if (m_jmingqi < 0)		{
			m_jmingqi = 0;
		}
	}	else	{
		m_jneili -= 2;
		if (m_jneili < 0)		{
			m_jneili = 0;
		}
	}
	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("黑市小贩"));
	m_shuxing[m_xingdong][em_caozuo] = em_xiaofan;
	m_jishu[em_xiaofan]++;

	TiaozhuanList();
	AddXingdong();
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtWDashou()
{
	// TODO: 在此添加控件通知处理程序代码
	// 打手		13岁,内力>110,到赌场解锁		金+190,气质-1,智力/道德-3
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	if (m_jpilao >= 300)
		return;
	m_jpilao += 18;
	m_jjinqian += 190;

	m_jqizhi -= 1;
	if (m_jqizhi < 0) {
		m_jqizhi = 0;
	}

	int n = rand() % 2;
	if (0 == n) {
		m_jzhili -= 3;
		if (m_jzhili < 0) {
			m_jzhili = 0;
		}
	}	else {
		m_jdaode -= 3;
		if (m_jdaode < 0) {
			m_jdaode = 0;
		}
	}
	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("打手"));
	m_shuxing[m_xingdong][em_caozuo] = em_dashou;
	m_jishu[em_dashou]++;

	TiaozhuanList();
	AddXingdong();
	UpdateData(FALSE);

}


void Cxy2simulatorDlg::OnBnClickedBtWMaimeng()
{
	// TODO: 在此添加控件通知处理程序代码
	// 卖萌要钱	13岁(要800W大话币/1000W师门)	金+900
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	if (m_jpilao >= 300)
		return;
	m_jpilao += 18;
	m_jjinqian += 190;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("卖萌要钱"));
	m_shuxing[m_xingdong][em_caozuo] = em_maimeng;
	m_jishu[em_maimeng]++;

	TiaozhuanList();
	AddXingdong();
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtWPaotang()
{
	// TODO: 在此添加控件通知处理程序代码
	// 青楼跑堂	14岁,耐力>130,到青楼			金+220,气质/名气/道德-2
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	if (m_jpilao >= 300)
		return;
	m_jpilao += 18;
	m_jjinqian += 220;

	int n = rand() % 3;
	if (0 == n) {
		m_jqizhi -= 2;
		if (m_jqizhi < 0) {
			m_jqizhi = 0;
		}
	}
	else if (1 == n) {
		m_jmingqi -= 2;
		if (m_jmingqi < 0) {
			m_jmingqi = 0;
		}
	}
	else {
		m_jdaode -= 2;
		if (m_jdaode < 0) {
			m_jdaode = 0;
		}
	}
	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("青楼跑堂"));
	m_shuxing[m_xingdong][em_caozuo] = em_paotang;
	m_jishu[em_paotang]++;

	TiaozhuanList();
	AddXingdong();
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtLGuozijian()
{
	// TODO: 在此添加控件通知处理程序代码
	// 国子监		6岁		疲劳-20
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	m_jpilao -= 20;
	if (m_jpilao < 0)
		m_jpilao = 0;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("国子监"));
	m_shuxing[m_xingdong][em_caozuo] = em_guozijian;
	m_jishu[em_guozijian]++;

	TiaozhuanList();
	AddXingdong();
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtLZaijia()
{
	// TODO: 在此添加控件通知处理程序代码
	// 在家休息	6岁		疲劳-20
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	m_jpilao -= 20;
	if (m_jpilao < 0)
		m_jpilao = 0;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("在家休息"));
	m_shuxing[m_xingdong][em_caozuo] = em_zaijia;
	m_jishu[em_zaijia]++;

	TiaozhuanList();
	AddXingdong();
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtLHuanggong()
{
	// TODO: 在此添加控件通知处理程序代码
	// 皇宫		6岁		名气+26	
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	if (m_jjinqian < 120)
		return;

	m_jmingqi += 26;
	if (m_jmingqi > 1200)
		m_jmingqi = 1200;

	m_jjinqian -= 120;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("皇宫"));
	m_shuxing[m_xingdong][em_caozuo] = em_huanggong;
	m_jishu[em_huanggong]++;

	TiaozhuanList();
	AddXingdong();
	// 解锁
	if (0 == m_jiesuo[em_huogong] && m_sui >= 7)
	{
		m_jiesuo[em_huogong] = m_xingdong;
		m_btGhuogong.EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtLHaibian()
{
	// TODO: 在此添加控件通知处理程序代码
	// 海边		7岁		疲劳-24 
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	m_jpilao -= 24;
	if (m_jpilao < 0)
		m_jpilao = 0;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("海边"));
	m_shuxing[m_xingdong][em_caozuo] = em_haibian;
	m_jishu[em_haibian]++;

	TiaozhuanList();
	AddXingdong();
	// 解锁
	if (0 == m_jiesuo[em_shuishou] && m_sui >= 7 && m_hmingqi > 10)
	{
		m_jiesuo[em_shuishou] = m_xingdong;
		m_btGshuishou.EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtLYewai()
{
	// TODO: 在此添加控件通知处理程序代码
	// 野外		8岁		疲劳-28 
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	m_jpilao -= 28;
	if (m_jpilao < 0)
		m_jpilao = 0;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("野外"));
	m_shuxing[m_xingdong][em_caozuo] = em_yewai;
	m_jishu[em_yewai]++;

	TiaozhuanList();
	AddXingdong();
	// 解锁
	if (0 == m_jiesuo[em_shouyin] && m_sui >= 8 && m_hmingqi > 30)
	{
		m_jiesuo[em_shouyin] = m_xingdong;
		m_btGshouyin.EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtLTaiyiyuan()
{
	// TODO: 在此添加控件通知处理程序代码
	// 太医院		9岁		疲劳-32
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	m_jpilao -= 32;
	if (m_jpilao < 0)
		m_jpilao = 0;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("太医院"));
	m_shuxing[m_xingdong][em_caozuo] = em_taiyiyuan;
	m_jishu[em_taiyiyuan]++;

	TiaozhuanList();
	AddXingdong();
	// 解锁
	if (0 == m_jiesuo[em_jianyao] && m_sui >= 9 && m_hdaode > 50)
	{
		m_jiesuo[em_jianyao] = m_xingdong;
		m_btGjianyao.EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtLDifu()
{
	// TODO: 在此添加控件通知处理程序代码
	// 地府		10岁		疲劳-36,玩性+1,名气-1
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	m_jpilao -= 36;
	if (m_jpilao < 0)
		m_jpilao = 0;

	m_jwanxing += 1;
	if (m_jwanxing > 1200)
		m_jwanxing = 1200;
	m_jmingqi -= 1;
	if (m_jmingqi < 0)
		m_jmingqi = 0;
	
	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("地府"));
	m_shuxing[m_xingdong][em_caozuo] = em_difu;
	m_jishu[em_difu]++;

	TiaozhuanList();
	AddXingdong();
	// 解锁
	if (0 == m_jiesuo[em_yinlu] && m_sui >= 10 && m_hmingqi > 70 && m_hqizhi > 70)
	{
		m_jiesuo[em_yinlu] = m_xingdong;
		m_btGyinlu.EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtLHeishi()
{
	// TODO: 在此添加控件通知处理程序代码
	// 黑市		12岁		疲劳-38,玩性+2,智力-2
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	m_jpilao -= 38;
	if (m_jpilao < 0)
		m_jpilao = 0;

	m_jwanxing += 2;
	if (m_jwanxing > 1200)
		m_jwanxing = 1200;
	m_jzhili -= 2;
	if (m_jzhili < 0)
		m_jzhili = 0;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("黑市"));
	m_shuxing[m_xingdong][em_caozuo] = em_heishi;
	m_jishu[em_heishi]++;

	TiaozhuanList();
	AddXingdong();
	// 解锁
	if (0 == m_jiesuo[em_xiaofan] && m_sui >= 12 && m_hpanni > 90)
	{
		m_jiesuo[em_xiaofan] = m_xingdong;
		m_btGxiaofan.EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtLDuchang()
{
	// TODO: 在此添加控件通知处理程序代码
	// 赌场		13岁		疲劳-40,玩性+2,道德-2
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	m_jpilao -= 40;
	if (m_jpilao < 0)
		m_jpilao = 0;

	m_jwanxing += 2;
	if (m_jwanxing > 1200)
		m_jwanxing = 1200;
	m_jdaode -= 2;
	if (m_jdaode < 0)
		m_jdaode = 0;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("赌场"));
	m_shuxing[m_xingdong][em_caozuo] = em_duchang;
	m_jishu[em_duchang]++;

	TiaozhuanList();
	AddXingdong();
	// 解锁
	if (0 == m_jiesuo[em_dashou] && m_sui >= 13 && m_hneili > 110)
	{
		m_jiesuo[em_dashou] = m_xingdong;
		m_btGdashou.EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtLLvyou()
{
	// TODO: 在此添加控件通知处理程序代码
	// 旅游		13岁		疲劳-280,游戏币-800W/师门-1000W
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	m_jpilao -= 280;
	if (m_jpilao < 0)
		m_jpilao = 0;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("旅游"));
	m_shuxing[m_xingdong][em_caozuo] = em_lvyou;
	m_jishu[em_lvyou]++;

	TiaozhuanList();
	AddXingdong();
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtLQinglou()
{
	// TODO: 在此添加控件通知处理程序代码
	// 青楼		14岁		疲劳-40,玩性+2,气质-2
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	m_jpilao -= 40;
	if (m_jpilao < 0)
		m_jpilao = 0;

	m_jwanxing += 2;
	if (m_jwanxing > 1200)
		m_jwanxing = 1200;
	m_jqizhi -= 2;
	if (m_jqizhi < 0)
		m_jqizhi = 0;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("青楼"));
	m_shuxing[m_xingdong][em_caozuo] = em_qinglou;
	m_jishu[em_qinglou]++;

	TiaozhuanList();
	AddXingdong();
	// 解锁
	if (0 == m_jiesuo[em_paotang] && m_sui >= 14 && m_hnaili > 130)
	{
		m_jiesuo[em_paotang] = m_xingdong;
		m_btGpaotang.EnableWindow(TRUE);
	}
	UpdateData(FALSE);

}


void Cxy2simulatorDlg::OnBnClickedBtSYinlv()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	if (m_jpilao >= 300)
		return;
	if (m_jjinqian < 120)
		return;

	m_jpilao += 18;
	m_jjinqian -= 120;

	m_jqizhi += 24;
	if (m_jqizhi > 1200)
		m_jqizhi = 1200;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("音律"));
	m_shuxing[m_xingdong][em_caozuo] = em_yinlv;
	m_jishu[em_yinlv]++;

	TiaozhuanList();
	AddXingdong();
	// 解锁
	if (0 == m_jiesuo[em_yinlv] && m_jishu[em_yinlv] >= 30)
	{
		m_jiesuo[em_yinlv] = m_xingdong;
		m_btXwudao.EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtSMeishu()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	if (m_jpilao >= 300)
		return;
	if (m_jjinqian < 120)
		return;

	m_jpilao += 18;
	m_jjinqian -= 120;

	m_jnaili += 24;
	if (m_jnaili > 1200)
		m_jnaili = 1200;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("美术"));
	m_shuxing[m_xingdong][em_caozuo] = em_meishu;
	m_jishu[em_meishu]++;

	TiaozhuanList();
	AddXingdong();
	// 解锁
	if (0 == m_jiesuo[em_meishu] && m_jishu[em_meishu] >= 30)
	{
		m_jiesuo[em_meishu] = m_xingdong;
		m_btXjianzhu.EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtSShiwen()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	if (m_jpilao >= 300)
		return;
	if (m_jjinqian < 120)
		return;

	m_jpilao += 18;
	m_jjinqian -= 120;

	m_jzhili += 24;
	if (m_jzhili > 1200)
		m_jzhili = 1200;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("诗文"));
	m_shuxing[m_xingdong][em_caozuo] = em_shiwen;
	m_jishu[em_shiwen]++;

	TiaozhuanList();
	AddXingdong();
	// 解锁
	if (0 == m_jiesuo[em_shiwen] && m_jishu[em_shiwen] >= 30)
	{
		m_jiesuo[em_shiwen] = m_xingdong;
		m_btXzongjiao.EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtSWushu()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	if (m_jpilao >= 300)
		return;
	if (m_jjinqian < 120)
		return;

	m_jpilao += 18;
	m_jjinqian -= 120;

	m_jneili += 24;
	if (m_jneili > 1200)
		m_jneili = 1200;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("武术"));
	m_shuxing[m_xingdong][em_caozuo] = em_wushu;
	m_jishu[em_wushu]++;

	TiaozhuanList();
	AddXingdong();
	// 解锁
	if (0 == m_jiesuo[em_wushu] && m_jishu[em_wushu] >= 30)
	{
		m_jiesuo[em_wushu] = m_xingdong;
		m_btXqishu.EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtSWudao()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	if (m_jpilao >= 300)
		return;
	if (m_jjinqian < 120)
		return;

	m_jpilao += 18;
	m_jjinqian -= 120;

	m_jqizhi += 22;
	if (m_jqizhi > 1200)
		m_jqizhi = 1200;
	m_jnaili += 2;
	if (m_jnaili > 1200)
		m_jnaili = 1200;
	m_jzhili += 2;
	if (m_jzhili > 1200)
		m_jzhili = 1200;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("舞蹈"));
	m_shuxing[m_xingdong][em_caozuo] = em_wudao;
	m_jishu[em_wudao]++;

	TiaozhuanList();
	AddXingdong();
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtSJianzhu()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	if (m_jpilao >= 300)
		return;
	if (m_jjinqian < 120)
		return;

	m_jpilao += 18;
	m_jjinqian -= 120;

	m_jnaili += 22;
	if (m_jnaili > 1200)
		m_jnaili = 1200;
	m_jneili += 2;
	if (m_jneili > 1200)
		m_jneili = 1200;
	m_jzhili += 2;
	if (m_jzhili > 1200)
		m_jzhili = 1200;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("建筑"));
	m_shuxing[m_xingdong][em_caozuo] = em_jianzhu;
	m_jishu[em_jianzhu]++;

	TiaozhuanList();
	AddXingdong();
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtSZongjiao()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	if (m_jpilao >= 300)
		return;
	if (m_jjinqian < 120)
		return;

	m_jpilao += 18;
	m_jjinqian -= 120;

	m_jzhili += 22;
	if (m_jzhili > 1200)
		m_jzhili = 1200;
	m_jqizhi += 2;
	if (m_jqizhi > 1200)
		m_jqizhi = 1200;
	m_jneili += 2;
	if (m_jneili > 1200)
		m_jneili = 1200;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("宗教"));
	m_shuxing[m_xingdong][em_caozuo] = em_zongjiao;
	m_jishu[em_zongjiao]++;

	TiaozhuanList();
	AddXingdong();
	UpdateData(FALSE);
}


void Cxy2simulatorDlg::OnBnClickedBtSQishu()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_xingdong >= em_max_oper) {
		MessageBox(_T("孩子已结局"), _T("提示"), MB_OK);
		return;
	}
	if (m_jpilao >= 300)
		return;
	if (m_jjinqian < 120)
		return;

	m_jpilao += 18;
	m_jjinqian -= 120;

	m_jneili += 22;
	if (m_jneili > 1200)
		m_jneili = 1200;
	m_jnaili += 2;
	if (m_jnaili > 1200)
		m_jnaili = 1200;
	m_jqizhi += 2;
	if (m_jqizhi > 1200)
		m_jqizhi = 1200;

	JiluShuxing();
	SetList1ItemText();
	m_list.SetItemText(m_xingdong, em_caozuo, _T("骑术"));
	m_shuxing[m_xingdong][em_caozuo] = em_qishu;
	m_jishu[em_qishu]++;

	TiaozhuanList();
	AddXingdong();
	UpdateData(FALSE);

}


void Cxy2simulatorDlg::OnBnClickedBtQingling()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	memset(m_jishu, 0, sizeof(m_jishu));
	UpdateData(FALSE);
}
