void res_vs_pos_new_bar()
{
    Float_t position[3],sigma1[3],sigma2[3];

    position[0] = 10.;
    position[1] = 70.;
    position[2] = 130.;

    sigma1[0] = 53.2;
    sigma1[1] = 65.6;
    sigma1[2] = 105.0;

    sigma2[0] = 95.9;
    sigma2[1] = 61.7;
    sigma2[2] = 47.2;


    Float_t position_err[3],sigma1_err[3],sigma2_err[3];

    position_err[0] = 0.05;
    position_err[1] = 0.05;
    position_err[2] = 0.05;

    sigma1_err[0] = 0.2;
    sigma1_err[1] = 0.1;
    sigma1_err[2] = 0.1;

    sigma2_err[0] = 0.2;
    sigma2_err[1] = 0.2;
    sigma2_err[2] = 0.3;


    /*
    Float_t sigma[3];

    sigma[0] = sqrt((pow(sigma1[0], 2) + pow(sigma2[0], 2))/4);
    sigma[1] = sqrt((pow(sigma1[1], 2) + pow(sigma2[1], 2))/4);
    sigma[2] = sqrt((pow(sigma1[2], 2) + pow(sigma2[2], 2))/4);
    */

    TLegend *legend = new TLegend(0.4,0.8,0.95,0.9);

    TGraphErrors *gr_sigma1 = new TGraphErrors(3,position,sigma1,position_err,sigma1_err);
    gr_sigma1->SetMarkerStyle(20);
    gr_sigma1->SetMarkerColor(kRed);
    gr_sigma1->SetLineColor(kRed);
    legend->AddEntry(gr_sigma1,"left PMT R13435","lp");

    TGraphErrors *gr_sigma2 = new TGraphErrors(3,position,sigma2,position_err,sigma2_err);
    gr_sigma2->SetMarkerStyle(20);
    gr_sigma2->SetMarkerColor(kRed);
    gr_sigma2->SetLineColor(kRed);
    gr_sigma2->SetLineStyle(2);
    legend->AddEntry(gr_sigma2,"right PMT R13435","lp");


    TCanvas *c2 = new TCanvas("resolution_vs_position","resolution_vs_position",500,500);
    c2->cd();

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

    c2->SetLeftMargin(0.15);
    c2->SetRightMargin(0.05);

    legend->Draw();
}
