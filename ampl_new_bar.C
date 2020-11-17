Float_t att_length(Float_t pos1, Float_t pos2, Float_t ampl1, Float_t ampl2)
{

    return (pos2-pos1)/log(ampl1/ampl2);

};


void ampl_new_bar()
{
    Float_t position[3],ampl1[3],ampl2[3];

    Float_t position_err[3],ampl1_err[3],ampl2_err[3];

    position[0] = 10.;
    position[1] = 70.;
    position[2] = 130.;

    position_err[0] = 0.05;
    position_err[1] = 0.05;
    position_err[2] = 0.05;


    ampl1[0] = 1850.;
    ampl1[1] = 1200.;
    ampl1[2] = 900.;

    ampl1_err[0] = 30.;
    ampl1_err[1] = 30.;
    ampl1_err[2] = 30.;


    ampl2[0] = 860.;
    ampl2[1] = 1200.;
    ampl2[2] = 1800.;

    ampl2_err[0] = 30.;
    ampl2_err[1] = 30.;
    ampl2_err[2] = 30.;


    cout << att_length(position[1],position[0],ampl1[1],ampl1[0]) << endl;
    cout << att_length(position[2],position[1],ampl1[2],ampl1[1]) << endl;
    cout << att_length(position[2],position[0],ampl1[2],ampl1[0]) << endl;

    cout << "###########################" << endl;

    cout << att_length(position[1],position[0],ampl2[0],ampl2[1]) << endl;
    cout << att_length(position[2],position[1],ampl2[1],ampl2[2]) << endl;
    cout << att_length(position[2],position[0],ampl2[0],ampl2[2]) << endl;


    TCanvas *c6 = new TCanvas("amplitudes","amplitudes",500,500);

    TGraphErrors *gr_ampl1 = new TGraphErrors(3,position,ampl1,position_err,ampl1_err);

    gr_ampl1->SetMarkerStyle(21);
    TLatex  *l1 = new TLatex(position[0]-5.,ampl1[0]-40.,Form("%i",1));
        l1->SetTextSize(0.035);
        l1->SetTextFont(42);
        l1->SetTextAlign(21);
        gr_ampl1->GetListOfFunctions()->Add(l1);
    TLatex  *l2 = new TLatex(position[1]-5.,ampl1[1],Form("%i",2));
        l2->SetTextSize(0.035);
        l2->SetTextFont(42);
        l2->SetTextAlign(21);
        gr_ampl1->GetListOfFunctions()->Add(l2);
    TLatex  *l3 = new TLatex(position[2]-5.,ampl1[2]+5,Form("%i",3));
        l3->SetTextSize(0.035);
        l3->SetTextFont(42);
        l3->SetTextAlign(21);
        gr_ampl1->GetListOfFunctions()->Add(l3);
    gr_ampl1->Draw("AP");


    TF1 *expo_left = new TF1("expo_left","[0]*exp(-x/[1])",0,140);
    expo_left->SetParNames("a_left", "lm_left");
    expo_left->SetParameters(2600,170);
    expo_left->SetLineColor(kBlack);

    gr_ampl1->Fit("expo_left");

    Double_t lambda_l = expo_left->GetParameter(1);
    Double_t lambda_l_err = expo_left->GetParError(1);


    TGraphErrors *gr_ampl2 = new TGraphErrors(3,position,ampl2,position_err,ampl2_err);

    gr_ampl2->SetMarkerStyle(20);
    gr_ampl2->SetMarkerColor(kRed);
    gr_ampl2->SetLineColor(kRed);
    TLatex  *l21 = new TLatex(position[0]-5.,ampl2[0]-30.,Form("%i",1));
        l21->SetTextSize(0.035);
        l21->SetTextFont(42);
        l21->SetTextColor(2);
        l21->SetTextAlign(21);
        gr_ampl2->GetListOfFunctions()->Add(l21);
    TLatex  *l22 = new TLatex(position[1]+5.,ampl2[1]-40.,Form("%i",2));
        l22->SetTextSize(0.035);
        l22->SetTextFont(42);
        l22->SetTextColor(2);
        l22->SetTextAlign(21);
        gr_ampl2->GetListOfFunctions()->Add(l22);
    TLatex  *l23 = new TLatex(position[2]-5.,ampl2[2]-40.,Form("%i",3));
        l23->SetTextSize(0.035);
        l23->SetTextFont(42);
        l23->SetTextColor(2);
        l23->SetTextAlign(21);
        gr_ampl2->GetListOfFunctions()->Add(l23);
    gr_ampl2->Draw("P");


    TF1 *expo_right = new TF1("expo_right","[0]*exp(x/[1])",0,140);
    expo_right->SetParNames("a_right", "lm_right");
    expo_right->SetParameters(600,170);
    expo_right->SetLineColor(kRed);

    gr_ampl2->Fit("expo_right");

    Double_t lambda_r = expo_right->GetParameter(1);
    Double_t lambda_r_err = expo_right->GetParError(1);


    gr_ampl1->SetTitle("Amplitude vs position");
    gr_ampl1->GetXaxis()->SetTitle("position (cm)");
    gr_ampl1->GetYaxis()->SetTitle("Amplitude (mV)");


    c6->SetLeftMargin(0.15);
    c6->SetRightMargin(0.05);

    ostringstream tmp;

/*
    tmp << "#splitline{#lambda_{1,2} = " << roundf(att_length(position[1],position[0],ampl1[1],ampl1[0])*10.)/10. << " (cm)}{#splitline{" << "#lambda_{2,3} = " << roundf(att_length(position[2],position[1],ampl1[2],ampl1[1])*10.)/10. << " (cm)}{"<< "#lambda_{1,3} = " << roundf(att_length(position[2],position[0],ampl1[2],ampl1[0])*10.)/10. << " (cm)}}";
*/

    tmp << "#lambda_{left} = " << round(lambda_l*10.)/10. << "#pm" << round(lambda_l_err*10.)/10. << " (cm)";

    TLatex lambda1 = TLatex();
    lambda1.SetTextSize(0.035);
    lambda1.SetNDC();
    lambda1.DrawLatex(0.24, 0.82, tmp.str().c_str());

    tmp.str("");

/*
    tmp << "#splitline{#lambda_{1,2} = " << roundf(att_length(position[0],position[1],ampl2[1],ampl2[0])*10.)/10. << " (cm)}{#splitline{" << "#lambda_{2,3} = " << roundf(att_length(position[1],position[2],ampl2[2],ampl2[1])*10.)/10. << " (cm)}{"<< "#lambda_{1,3} = " << roundf(att_length(position[0],position[2],ampl2[2],ampl2[0])*10.)/10. << " (cm)}}";
*/

    tmp << "#lambda_{right} = " << round(lambda_r*10.)/10. << "#pm" << round(lambda_r_err*10.)/10. << " (cm)";

    TLatex lambda2 = TLatex();
    lambda2.SetTextSize(0.035);
    lambda2.SetTextColor(kRed);
    lambda2.SetNDC();
    lambda2.DrawLatex(0.58, 0.82, tmp.str().c_str());

    tmp.str("");
}
