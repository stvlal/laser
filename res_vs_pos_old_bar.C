void res_vs_pos_old_bar()
{
    Float_t position[3],sigma1[3],sigma2[3];

    position[0] = 10.;
    position[1] = 70.;
    position[2] = 130.;

    sigma1[0] = 55.0;
    sigma1[1] = 89.9;
    sigma1[2] = 143.4;

    sigma2[0] = 157.3;
    sigma2[1] = 95.0;
    sigma2[2] = 61.1;


    Float_t position_err[3],sigma1_err[3],sigma2_err[3];

    position_err[0] = 0.05;
    position_err[1] = 0.05;
    position_err[2] = 0.05;

    sigma1_err[0] = 0.3;
    sigma1_err[1] = 0.1;
    sigma1_err[2] = 0.1;

    sigma2_err[0] = 0.2;
    sigma2_err[1] = 0.2;
    sigma2_err[2] = 0.4;


    TLegend *legend = new TLegend(0.4,0.8,0.95,0.9);

    TGraphErrors *gr_sigma1 = new TGraphErrors(3,position,sigma1,position_err,sigma1_err);
    gr_sigma1->SetMarkerStyle(21);
    gr_sigma1->SetMarkerColor(kBlack);
    gr_sigma1->SetLineColor(kBlack);
    legend->AddEntry(gr_sigma1,"left PMT R13435","lp");

    TGraphErrors *gr_sigma2 = new TGraphErrors(3,position,sigma2,position_err,sigma2_err);
    gr_sigma2->SetMarkerStyle(21);
    gr_sigma2->SetMarkerColor(kBlack);
    gr_sigma2->SetLineColor(kBlack);
    gr_sigma2->SetLineStyle(2);
    legend->AddEntry(gr_sigma2,"right PMT R13435","lp");


    TCanvas *c1 = new TCanvas("resolution_vs_position","resolution_vs_position",500,500);
    c1->cd();

    gr_sigma2->GetHistogram()->SetMinimum(0.);
    gr_sigma2->GetHistogram()->SetMaximum(230.);

    gr_sigma1->GetHistogram()->SetMinimum(0.);
    gr_sigma1->GetHistogram()->SetMaximum(230.);

    TH1F *histo1 = gr_sigma1->GetHistogram();
    histo1->SetTitleSize(0.035);
    gr_sigma2->Draw("ACP");
    gr_sigma2->SetTitle("");
    gr_sigma2->GetXaxis()->SetTitle("position (cm)");
    gr_sigma2->GetYaxis()->SetTitle("resolution (ps)");

    TH1F *histo2 = gr_sigma2->GetHistogram();
    histo2->SetTitleSize(0.035);
    gr_sigma1->Draw("CP");

    c1->SetLeftMargin(0.15);
    c1->SetRightMargin(0.05);

    legend->Draw();
}
