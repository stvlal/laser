void sigma()
{
    Float_t position[3],sigma1_old_bar[3],sigma2_old_bar[3];

    position[0] = 10.;
    position[1] = 70.;
    position[2] = 130.;

    sigma1_old_bar[0] = 55.0;
    sigma1_old_bar[1] = 89.9;
    sigma1_old_bar[2] = 143.4;

    sigma2_old_bar[0] = 157.3;
    sigma2_old_bar[1] = 95.0;
    sigma2_old_bar[2] = 61.1;


    Float_t position_err[3],sigma1_err_old_bar[3],sigma2_err_old_bar[3];

    position_err[0] = 0.05;
    position_err[1] = 0.05;
    position_err[2] = 0.05;

    sigma1_err_old_bar[0] = 0.3;
    sigma1_err_old_bar[1] = 0.1;
    sigma1_err_old_bar[2] = 0.1;

    sigma2_err_old_bar[0] = 0.2;
    sigma2_err_old_bar[1] = 0.2;
    sigma2_err_old_bar[2] = 0.4;


    Float_t sigma_old_bar[3];

    sigma_old_bar[0] = sqrt((pow(sigma1_old_bar[0], 2) + pow(sigma2_old_bar[0], 2))/4);
    sigma_old_bar[1] = sqrt((pow(sigma1_old_bar[1], 2) + pow(sigma2_old_bar[1], 2))/4);
    sigma_old_bar[2] = sqrt((pow(sigma1_old_bar[2], 2) + pow(sigma2_old_bar[2], 2))/4);



    Float_t sigma1_new_bar[3],sigma2_new_bar[3];

    sigma1_new_bar[0] = 53.2;
    sigma1_new_bar[1] = 65.6;
    sigma1_new_bar[2] = 105.0;

    sigma2_new_bar[0] = 95.9;
    sigma2_new_bar[1] = 61.7;
    sigma2_new_bar[2] = 47.2;


    Float_t sigma1_err_new_bar[3],sigma2_err_new_bar[3];

    sigma1_err_new_bar[0] = 0.2;
    sigma1_err_new_bar[1] = 0.1;
    sigma1_err_new_bar[2] = 0.1;

    sigma2_err_new_bar[0] = 0.2;
    sigma2_err_new_bar[1] = 0.2;
    sigma2_err_new_bar[2] = 0.3;


    Float_t sigma_new_bar[3];

    sigma_new_bar[0] = sqrt((pow(sigma1_new_bar[0], 2) + pow(sigma2_new_bar[0], 2))/4);
    sigma_new_bar[1] = sqrt((pow(sigma1_new_bar[1], 2) + pow(sigma2_new_bar[1], 2))/4);
    sigma_new_bar[2] = sqrt((pow(sigma1_new_bar[2], 2) + pow(sigma2_new_bar[2], 2))/4);


    TLegend *legend = new TLegend(0.4,0.8,0.95,0.9);
    TCanvas *c4 = new TCanvas("sigma","sigma",500,500);
    c4->cd();

    TGraph *sigma_old = new TGraph(3,position,sigma_old_bar);
    sigma_old->SetMarkerStyle(21);
    sigma_old->SetMarkerColor(kBlack);
    sigma_old->SetLineColor(kBlack);
    sigma_old->SetLineWidth(2);

    sigma_old->GetHistogram()->SetMinimum(0.);
    sigma_old->GetHistogram()->SetMaximum(100.);

    TH1F *hist = sigma_old->GetHistogram();
    hist->SetTitleSize(0.035);
    sigma_old->Draw("ACP");
    sigma_old->SetTitle("");
    sigma_old->GetXaxis()->SetTitle("position (cm)");
    sigma_old->GetYaxis()->SetTitle("#sigma_{#frac{L+R}{2}} (ps)");
    legend->AddEntry(sigma_old,"old bar","lp");


    TGraph *sigma_new = new TGraph(3,position,sigma_new_bar);
    sigma_new->SetMarkerStyle(20);
    sigma_new->SetMarkerColor(kRed);
    sigma_new->SetLineColor(kRed);
    sigma_new->SetLineWidth(2);

    sigma_new->GetHistogram()->SetMinimum(0.);
    sigma_new->GetHistogram()->SetMaximum(100.);

    TH1F *hist1 = sigma_new->GetHistogram();
    hist1->SetTitleSize(0.035);
    sigma_new->Draw("CP");
    legend->AddEntry(sigma_new,"new bar","lp");

    legend->Draw();

    c4->SetLeftMargin(0.15);
    c4->SetRightMargin(0.05);


}
