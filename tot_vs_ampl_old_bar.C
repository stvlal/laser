void tot_vs_ampl_old_bar()
{
    gStyle->SetOptFit(1);
    gStyle->SetStatY(0.5);

    // PMT1 old bar

    Float_t tot1[3],ampl1[3];

    Float_t tot1_err[3],ampl1_err[3];

    tot1[0] = 29.29;
    tot1[1] = 27.22;
    tot1[2] = 23.17;

    tot1_err[0] = 0.5045;
    tot1_err[1] = 0.7133;
    tot1_err[2] = 0.7365;

    ampl1[0] = 2500.;
    ampl1[1] = 1350.;
    ampl1[2] = 800.;

    ampl1_err[0] = 30.;
    ampl1_err[1] = 30.;
    ampl1_err[2] = 30.;


    // PMT2 old bar

    Float_t tot2[3],ampl2[3];

    Float_t tot2_err[3],ampl2_err[3];

    tot2[0] = 21.75;
    tot2[1] = 25.32;
    tot2[2] = 25.11;

    tot2_err[0] = 0.7038;
    tot2_err[1] = 0.6084;
    tot2_err[2] = 0.4795;

    ampl2[0] = 720.;
    ampl2[1] = 1200.;
    ampl2[2] = 2200.;

    ampl2_err[0] = 30.;
    ampl2_err[1] = 30.;
    ampl2_err[2] = 30.;


    TCanvas *c7 = new TCanvas("amplitudes_vs_tot","amplitudes_vs_tot",1000,500);
    c7->Divide(2,1);


    // Drawing plot for PMT1

    c7->cd(1);
    c7->cd(1)->SetRightMargin(0.05);

    TGraphErrors *gr_ampl1 = new TGraphErrors(3,ampl1,tot1,ampl1_err,tot1_err);

    gr_ampl1->SetMarkerStyle(21);
    gr_ampl1->SetTitle("PMT 1 old bar");
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


    TF1 *parabola_pmt1 = new TF1("parabola_pmt1","[0]*x*x+[1]*x+[2]",800,1900);
    parabola_pmt1->SetParNames("c", "b", "a");
  //  parabola->SetParameters(,);
    parabola_pmt1->SetLineColor(kRed);

    gr_ampl1->Fit("parabola_pmt1");

/*
    TF1 *f1 = new TF1("f1","pol1");
    gr_ampl1->Fit(f1,"","",550.,1900.);
*/

    // Drawing plot for PMT2

    c7->cd(2);
    c7->cd(2)->SetLeftMargin(0.15);

    TGraphErrors *gr_ampl2 = new TGraphErrors(3,ampl2,tot2,ampl2_err,tot2_err);

    gr_ampl2->SetMarkerStyle(21);
    gr_ampl2->SetTitle("PMT 2 old bar");
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


    TF1 *parabola_pmt2 = new TF1("parabola_pmt2","[0]*x*x+[1]*x+[2]",800,1900);
    parabola_pmt2->SetParNames("c", "b", "a");
  //  parabola->SetParameters(,);
    parabola_pmt2->SetLineColor(kRed);

    gr_ampl2->Fit("parabola_pmt2");

/*
    TF1 *f2 = new TF1("f2","pol1");
    gr_ampl2->Fit(f2,"","",500.,1700.);
*/
}
