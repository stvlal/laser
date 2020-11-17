void tot_vs_ampl_new_bar()
{
    gStyle->SetOptFit(1);
    gStyle->SetStatY(0.5);

    // PMT1 new bar

    Float_t tot1[3],ampl1[3];

    Float_t tot1_err[3],ampl1_err[3];

    tot1[0] = 29.48;
    tot1[1] = 27.71;
    tot1[2] = 24.38;

    tot1_err[0] = 0.6233;
    tot1_err[1] = 0.6042;
    tot1_err[2] = 0.5698;

    ampl1[0] = 1850.;
    ampl1[1] = 1200.;
    ampl1[2] = 900.;

    ampl1_err[0] = 30.;
    ampl1_err[1] = 30.;
    ampl1_err[2] = 30.;


    // PMT2 new bar

    Float_t tot2[3],ampl2[3];

    Float_t tot2_err[3],ampl2_err[3];

    tot2[0] = 22.42;
    tot2[1] = 24.75;
    tot2[2] = 25.13;

    tot2_err[0] = 0.4747;
    tot2_err[1] = 0.4664;
    tot2_err[2] = 0.5262;

    ampl2[0] = 860.;
    ampl2[1] = 1200.;
    ampl2[2] = 1800.;

    ampl2_err[0] = 30.;
    ampl2_err[1] = 30.;
    ampl2_err[2] = 30.;


    TCanvas *c8 = new TCanvas("amplitudes_vs_tot","amplitudes_vs_tot",1000,500);
    c8->Divide(2,1);


    // Drawing plot for PMT1

    c8->cd(1);
    c8->cd(1)->SetRightMargin(0.05);

    TGraphErrors *gr_ampl1 = new TGraphErrors(3,ampl1,tot1,ampl1_err,tot1_err);

    gr_ampl1->SetMarkerStyle(21);
    gr_ampl1->SetTitle("PMT 1 new bar");
    gr_ampl1->GetXaxis()->SetTitle("Amplitude (mV)");
    gr_ampl1->GetYaxis()->SetTitle("ToT (ns)");
    TLatex  *l1 = new TLatex(ampl1[0]+80.,tot1[0]-0.2,Form("%i",1));
        l1->SetTextSize(0.035);
        l1->SetTextFont(42);
        l1->SetTextAlign(21);
        gr_ampl1->GetListOfFunctions()->Add(l1);
    TLatex  *l2 = new TLatex(ampl1[1]+80.,tot1[1]-0.2,Form("%i",2));
        l2->SetTextSize(0.035);
        l2->SetTextFont(42);
        l2->SetTextAlign(21);
        gr_ampl1->GetListOfFunctions()->Add(l2);
    TLatex  *l3 = new TLatex(ampl1[2]+80.,tot1[2]-0.2,Form("%i",3));
        l3->SetTextSize(0.035);
        l3->SetTextFont(42);
        l3->SetTextAlign(21);
        gr_ampl1->GetListOfFunctions()->Add(l3);
    gr_ampl1->Draw("AP");



    TF1 *expo1 = new TF1("expo1","[0]*sqrt(sqrt(sqrt(x)))+[1]",800,1900);
    expo1->SetParNames("a1", "b1");
  //  expo1->SetParameters();
    expo1->SetLineColor(kRed);

    gr_ampl1->Fit("expo1");

  //  Double_t lambda_l = expo_left->GetParameter(1);
  //  Double_t lambda_l_err = expo_left->GetParError(1);


/*
    TF1 *f1 = new TF1("f1","pol1");
    gr_ampl1->Fit(f1,"","",700.,1600.);
*/

    // Drawing plot for PMT2

    c8->cd(2);
    c8->cd(2)->SetLeftMargin(0.15);

    TGraphErrors *gr_ampl2 = new TGraphErrors(3,ampl2,tot2,ampl2_err,tot2_err);

    gr_ampl2->SetMarkerStyle(21);
    gr_ampl2->SetTitle("PMT 2 new bar");
    gr_ampl2->GetXaxis()->SetTitle("Amplitude (mV)");
    gr_ampl2->GetYaxis()->SetTitle("ToT (ns)");
    TLatex  *l21 = new TLatex(ampl2[0]+80.,tot2[0]-0.05,Form("%i",1));
        l21->SetTextSize(0.035);
        l21->SetTextFont(42);
        l21->SetTextAlign(21);
        gr_ampl2->GetListOfFunctions()->Add(l21);
    TLatex  *l22 = new TLatex(ampl2[1]+80.,tot2[1]-0.05,Form("%i",2));
        l22->SetTextSize(0.035);
        l22->SetTextFont(42);
        l22->SetTextAlign(21);
        gr_ampl2->GetListOfFunctions()->Add(l22);
    TLatex  *l23 = new TLatex(ampl2[2]+80.,tot2[2]-0.05,Form("%i",3));
        l23->SetTextSize(0.035);
        l23->SetTextFont(42);
        l23->SetTextAlign(21);
        gr_ampl2->GetListOfFunctions()->Add(l23);
    gr_ampl2->Draw("AP");


    TF1 *expo2 = new TF1("expo2","[0]*sqrt(sqrt(sqrt(x)))+[1]",800,1900);
    expo2->SetParNames("a2", "b2");
  //  expo_left->SetParameters(2600,170);
    expo2->SetLineColor(kRed);

    gr_ampl2->Fit("expo2");

/*
    TF1 *parabola_pmt2 = new TF1("parabola_pmt2","[0]*x*x+[1]*x+[2]",800,1900);
    parabola_pmt2->SetParNames("c", "b", "a");
    parabola_pmt2->FixParameter(1,0);
  //  parabola->SetParameters(,);
    parabola_pmt2->SetLineColor(kRed);

    gr_ampl2->Fit("parabola_pmt2");
*/
/*
    TF1 *f2 = new TF1("f2","pol1");
    gr_ampl2->Fit(f2,"","",500.,1700.);
*/
}
