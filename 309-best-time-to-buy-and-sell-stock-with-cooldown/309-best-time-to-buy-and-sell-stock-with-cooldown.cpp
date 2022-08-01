class Solution {
public:

int maxProfit(vector<int> &ar)
{
    int n = ar.size();
    if (n <= 1)
    {
        return 0;
    }

    int obp = -ar[0];
    int osp = 0;
    int ocp = 0; 

    for (int i = 1; i < n; i++)
    {
        int nbp = 0 , nsp = 0 , ncp = 0;
        nbp = max(obp, ocp - ar[i]);
        nsp = max(osp, ar[i] + obp);
        ncp = max(ocp, osp);

        obp = nbp;
        osp = nsp;
        ocp = ncp;
    }

    return osp;

}
};