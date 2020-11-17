void weighted_mean()
{
    Float_t position[3],sigma1[3],sigma2[3],weighted_mean_new_bar[3];

    position[0] = 10.;
    position[1] = 70.;
    position[2] = 130.;

    sigma1[0] = 53.2;
    sigma1[1] = 65.6;
    sigma1[2] = 105.0;

    sigma2[0] = 95.9;
    sigma2[1] = 61.7;
    sigma2[2] = 47.2;

    weighted_mean_new_bar[0] = sigma1[0]*sigma2[0]/sqrt(sigma1[0]*sigma1[0]+sigma2[0]*sigma2[0]);
    weighted_mean_new_bar[1] = sigma1[1]*sigma2[1]/sqrt(sigma1[1]*sigma1[1]+sigma2[1]*sigma2[1]);
    weighted_mean_new_bar[2] = sigma1[2]*sigma2[2]/sqrt(sigma1[2]*sigma1[2]+sigma2[2]*sigma2[2]);


    Float_t sigma3[3],sigma4[3],weighted_mean_old_bar[3];

    sigma3[0] = 55.0;
    sigma3[1] = 89.9;
    sigma3[2] = 143.4;

    sigma4[0] = 157.3;
    sigma4[1] = 95.0;
    sigma4[2] = 61.1;

    weighted_mean_old_bar[0] = sigma3[0]*sigma4[0]/sqrt(sigma3[0]*sigma3[0]+sigma4[0]*sigma4[0]);
    weighted_mean_old_bar[1] = sigma3[1]*sigma4[1]/sqrt(sigma3[1]*sigma3[1]+sigma4[1]*sigma4[1]);
    weighted_mean_old_bar[2] = sigma3[2]*sigma4[2]/sqrt(sigma3[2]*sigma3[2]+sigma4[2]*sigma4[2]);


    TCanvas *c3 = new TCanvas("weighted_mean","weighted_mean",500,500);

    c3->cd();
    c3->SetLeftMargin(0.15);
    c3->SetRightMargin(0.05);


    TLegend *legend = new TLegend(0.4,0.8,0.95,0.9);
    TGraph *gr_weighted_mean_new_bar = new TGraph(3,position,weighted_mean_new_bar);
    TGraph *gr_weighted_mean_old_bar = new TGraph(3,position,weighted_mean_old_bar);


    gr_weighted_mean_new_bar->SetMarkerStyle(20);
    gr_weighted_mean_new_bar->SetLineColor(kRed);
    gr_weighted_mean_new_bar->SetMarkerColor(kRed);
    gr_weighted_mean_new_bar->GetHistogram()->SetMinimum(0.);
    gr_weighted_mean_new_bar->GetHistogram()->SetMaximum(230.);
    gr_weighted_mean_new_bar->SetTitle("");
    gr_weighted_mean_new_bar->GetXaxis()->SetTitle("position (cm)");
    gr_weighted_mean_new_bar->GetYaxis()->SetTitle("resolution (ps)");
    TH1F *histo = gr_weighted_mean_new_bar->GetHistogram();
    histo->SetTitleSize(0.035);
    gr_weighted_mean_new_bar->Draw("ACP");


    gr_weighted_mean_old_bar->SetMarkerStyle(21);
    gr_weighted_mean_old_bar->SetLineColor(kBlack);
    gr_weighted_mean_old_bar->SetMarkerColor(kBlack);
    gr_weighted_mean_old_bar->Draw("CP");
    legend->AddEntry(gr_weighted_mean_old_bar,"old bar","lp");
    legend->AddEntry(gr_weighted_mean_new_bar,"new bar","lp");
    legend->Draw();
}
