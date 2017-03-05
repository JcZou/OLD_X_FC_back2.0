#ifndef _PPCFFRELS_h_
#define _PPCFFRELS_h_

//递推增广最小二乘估计的相关定义

#define  PPCFFRELS_ML_A 10  //定义辨识用 全局初始化的 向量和矩阵的最大维度，请确保这个值大于每一个RELS结构体内的ML



//----------------Data struct---------------------------//

typedef struct {
//varitable
	
	//这几个数初始化以后就千万不要再乱改了，不好，不好
	int NA;      //被控系统A的阶次
	int NB;      //被控系统B的阶次
	int D;       //d延迟
	
	//中间变量
	int NF;      //F的阶数
	int NG;      //G的阶数
	int NR;      //R的阶数
	int NAM;     //Am的阶次
	int NA0;     //A0的阶次
	int NAA;     //A0*Am的阶次
	int ML;      // ML=NF+1+NG+1 定义辨识用向量和矩阵的最大维度(因为nf1也要辨识1作为be0所以也要加1)
	float AM[1][PPCFFRELS_ML_A];   //目标系统分母多项式系数Am
	float A0[1][PPCFFRELS_ML_A];   //目标系统分母多项式系数A0
	float AA[1][PPCFFRELS_ML_A];   //目标系统分母多项式系数A0*Am
	float BE0;                   //be0
	float FE[1][PPCFFRELS_ML_A];   //控制器的F
	float GE[1][PPCFFRELS_ML_A];   //控制器的G
	float R[1][PPCFFRELS_ML_A];                     //控制器的R
	
	//观测用的矩阵
	float phie[PPCFFRELS_ML_A][1];  //ψ
	float P[PPCFFRELS_ML_A][PPCFFRELS_ML_A];  //单位阵P
	float thetae_1[PPCFFRELS_ML_A][1];  //θ的前一次的值，初始化为初值
	float thetae[PPCFFRELS_ML_A][1];  //θ的初值
	float K[PPCFFRELS_ML_A][1];  //K
	

//function none
}PPCFFRELS_T;



void PPCFFRELS_init(PPCFFRELS_T* relsIn, int na, int nb, int d, float am1, float am2, float am3);
void PPCFFRELS_initAsSteady(PPCFFRELS_T* relsIn, int na, int nb, int d, float am1, float am2, float am3);
void PPCFFRELS_Update(PPCFFRELS_T* relsIn, float CDataYFK[], float CDataUFK[], float lambda);
void PPCFFRELS_ClcFGR(PPCFFRELS_T* relsIn);



















#endif
