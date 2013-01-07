#include <iostream>
#include "inferenceSystem.h"

using namespace std;
using namespace Fuzzy;

int main()
{
	InferenceSystem* fis;
	fis = new InferenceSystem;
	LinguisticVariable* lv;
	RuleDescriptor* rd = new RuleDescriptor;
	float params[3];

	lv = fis->AddInputLV("position", -1.0f, 1.0f);
	params[0] = -1.0f; params[1] = -1.0f; params[2] = 0.0f;
	lv->AddTriMF("left", params);
	//*
	params[0] = -0.5f; params[1] = 0.0f; params[2] = 0.5f;
	lv->AddTriMF("mid", params);
	params[0] = 0.0f; params[1] = 1.0f; params[2] = 1.0f;
	lv->AddTriMF("right", params);
	//*

	lv = fis->AddInputLV("velocity", -1.0f, 1.0f);
	params[0] = -1.0f; params[1] = -1.0f; params[2] = 0.0f;
	lv->AddTriMF("left", params);
	//*
	params[0] = -0.5f; params[1] = 0.0f; params[2] = 0.5f;
	lv->AddTriMF("slow", params);
	params[0] = 0.0f; params[1] = 1.0f; params[2] = 1.0f;
	lv->AddTriMF("right", params);
	//*/

	lv = fis->AddOutputLV("steer", -1.0f, 1.0f);
	params[0] = -1.1f; params[1] = -1.0f; params[2] = 0.0f;
	lv->AddTriMF("left", params);
	//*
	params[0] = -0.5f; params[1] = 0.0f; params[2] = 0.5f;
	lv->AddTriMF("center", params);
	params[0] = 0.0f; params[1] = 1.0f; params[2] = 1.1f;
	lv->AddTriMF("right", params);
	//*/


	rd->AddInPair("position", "left");
	rd->AddInPair("velocity", "left");
	rd->AddOutPair("steer", "right");

	fis->AddRule(rd, 0);
	
	float input[2] = {0.0f, 0.0f};
	cout << fis->Evaluate(input)[0] << endl;
	cout << lv->GetMF("left")->Fuzzify(-.2);

	return 0;
}