#include <iostream>
#include "inferenceSystem.h"

using namespace std;
using namespace Fuzzy;

int main()
{
	InferenceSystem* fis;
	fis = new InferenceSystem;
	LinguisticVariable* lv, *lv1, *lv2, *lv3;
	RuleDescriptor rd[9];
	float params[3];

	lv1 = fis->AddInputLV("position", -1.0f, 1.0f);
	params[0] = -2.0f; params[1] = -1.0f; params[2] = 0.0f;
	lv1->AddTriMF("left", params);
	params[0] = -0.5f; params[1] = 0.0f; params[2] = 0.5f;
	lv1->AddTriMF("mid", params);
	params[0] = 0.0f; params[1] = 1.0f; params[2] = 2.0f;
	lv1->AddTriMF("right", params);
	
	lv2 = fis->AddInputLV("velocity", -1.0f, 1.0f);
	params[0] = -2.0f; params[1] = -1.0f; params[2] = 0.0f;
	lv2->AddTriMF("left", params);
	params[0] = -0.5f; params[1] = 0.0f; params[2] = 0.5f;
	lv2->AddTriMF("slow", params);
	params[0] = 0.0f; params[1] = 1.0f; params[2] = 2.0f;
	lv2->AddTriMF("right", params);
	
	lv3 = fis->AddOutputLV("steer", -1.0f, 1.0f);
	params[0] = -1.0f; params[1] = -.75f; params[2] = -.5f;
	lv3->AddTriMF("left", params);
	params[0] = -0.5f; params[1] = 0.0f; params[2] = 0.5f;
	lv3->AddTriMF("center", params);
	params[0] = 0.5f; params[1] = 0.75f; params[2] = 1.0f;
	lv3->AddTriMF("right", params);
	
	rd[0].AddInPair("position", "left");
	rd[0].AddInPair("velocity", "left");
	rd[0].AddOutPair("steer", "right");
	fis->AddRule(&rd[0], 0);
	
	rd[1].AddInPair("position", "left");
	rd[1].AddInPair("velocity", "slow");
	rd[1].AddOutPair("steer", "right");
	fis->AddRule(&rd[1], 0);

	rd[2].AddInPair("position", "left");
	rd[2].AddInPair("velocity", "right");
	rd[2].AddOutPair("steer", "center");
	fis->AddRule(&rd[2], 0);

	rd[3].AddInPair("position", "mid");
	rd[3].AddInPair("velocity", "left");
	rd[3].AddOutPair("steer", "right");
	fis->AddRule(&rd[3], 0);
	
	rd[4].AddInPair("position", "mid");
	rd[4].AddInPair("velocity", "slow");
	rd[4].AddOutPair("steer", "center");
	fis->AddRule(&rd[4], 0);

	rd[5].AddInPair("position", "mid");
	rd[5].AddInPair("velocity", "right");
	rd[5].AddOutPair("steer", "left");
	fis->AddRule(&rd[5], 0);

	rd[6].AddInPair("position", "right");
	rd[6].AddInPair("velocity", "left");
	rd[6].AddOutPair("steer", "center");
	fis->AddRule(&rd[6], 0);
	
	rd[7].AddInPair("position", "right");
	rd[7].AddInPair("velocity", "slow");
	rd[7].AddOutPair("steer", "left");
	fis->AddRule(&rd[7], 0);

	rd[8].AddInPair("position", "right");
	rd[8].AddInPair("velocity", "right");
	rd[8].AddOutPair("steer", "left");
	fis->AddRule(&rd[8], 0);

	float input[2];
	float temp;

	cout << lv1->GetMF("left")->Centroid() << endl;
	cout << lv1->GetMF("mid")->Centroid() << endl;
	cout << lv1->GetMF("right")->Centroid() << endl;

	cout << lv2->GetMF("left")->Centroid() << endl;
	cout << lv2->GetMF("slow")->Centroid() << endl;
	cout << lv2->GetMF("right")->Centroid() << endl;

	cout << lv3->GetMF("left")->Centroid() << endl;
	cout << lv3->GetMF("center")->Centroid() << endl;
	cout << lv3->GetMF("right")->Centroid() << endl;

	for (int i=0; i< 20; i++)
	{
		temp = -1.0 + (i/20.0f) * 2;
		input[0] = temp;
		input[1] = temp;
		cout << temp << ", " << fis->Evaluate(input)[0] << endl;
	}

	return 0;
}