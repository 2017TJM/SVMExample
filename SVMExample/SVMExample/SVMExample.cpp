/* --------------------------------------------------------
* ���ߣ�livezingy
*
* ���ͣ�http://www.livezingy.com
*
* ����������
*      Visual Studio V2013
opencv3.1
*
* �汾��ʷ��
*      V1.0    2017��1��30��
��ʹ��LBP����,HOG����,SIFT/SURF����ʵ��SVMѵ��
--------------------------------------------------------- */

#include "stdafx.h"
#include "svm_train.h"

using namespace cv;
string resPath;

int main(int argc, char** argv)
{	
    SvmTrain svmTr = SvmTrain();
	
    FileStorage paramsFS("params.xml", FileStorage::READ);
	
	if (paramsFS.isOpened())
	{
		FileNode currFn = paramsFS["resPath"];
		
		currFn >> resPath;
		
		currFn = paramsFS["featureType"];
		string featureType = "";
		currFn >> featureType;
		
		if((featureType == "LBP") || (featureType == "HOG"))
		{
			svmTr.feaType = featureType;
			
			svmTr.trainAuto();
		}
		else
		{
			svmTr.getBOWFeatures();
		}
	}
	else
	{
		//params.xml should be in the same path with SVMExample.vcxproj
		cout << "Open params.xml fail, please make sure the params.xml in the right path!" << endl;
		
	}
	
	//keep console 
    cin.get();
	
	return 0;
}

