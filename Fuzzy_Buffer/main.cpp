#include <iostream>
#include "inferenceSystem.h"

using namespace std;
using namespace Fuzzy;

int main()
{
	InferenceSystem* fis;
	fis = new InferenceSystem;
	LinguisticVariable* lv, *lv1, *lv2, *lv3;
	RuleDescriptor* rd = new RuleDescriptor;
	float params[3];

	lv1 = fis->AddInputLV("position", -1.0f, 1.0f);
	params[0] = -1.1f; params[1] = -1.0f; params[2] = 0.0f;
	lv1->AddTriMF("left", params);
	params[0] = -0.5f; params[1] = 0.0f; params[2] = 0.5f;
	lv1->AddTriMF("mid", params);
	params[0] = 0.0f; params[1] = 1.0f; params[2] = 1.1f;
	lv1->AddTriMF("right", params);
	
	lv2 = fis->AddInputLV("velocity", -1.0f, 1.0f);
	params[0] = -1.1f; params[1] = -1.0f; params[2] = 0.0f;
	lv2->AddTriMF("left", params);
	params[0] = -0.5f; params[1] = 0.0f; params[2] = 0.5f;
	lv2->AddTriMF("slow", params);
	params[0] = 0.0f; params[1] = 1.0f; params[2] = 1.1f;
	lv2->AddTriMF("right", params);
	
	lv3 = fis->AddOutputLV("steer", -1.0f, 1.0f);
	params[0] = -1.1f; params[1] = -1.0f; params[2] = 0.0f;
	lv3->AddTriMF("left", params);
	params[0] = -0.5f; params[1] = 0.0f; params[2] = 0.5f;
	lv3->AddTriMF("center", params);
	params[0] = 0.0f; params[1] = 1.0f; params[2] = 1.1f;
	lv3->AddTriMF("right", params);
	
	rd->AddInPair("position", "left");
	rd->AddInPair("velocity", "left");
	rd->AddOutPair("steer", "right");

	fis->AddRule(rd, 0);
	
	float input[2] = {-0.9f, -0.9f};
	cout << fis->Evaluate(input)[0] << endl;
	
	cout << lv1->GetMF("left")->Fuzzify(0.0f) << endl;
	cout << lv1->GetMF("mid")->Fuzzify(0.0f) << endl;
	cout << lv1->GetMF("right")->Fuzzify(0.0f) << endl;

	return 0;
}