//#include "leaderboard.h"
//#include "lib.h"
//
//void Leader::LoadLeaderboardInfo()
//{
//    string name;
//    double points = 0;
//    ifstream fi("info.txt");
//    if (fi)
//    {
//        fi >> numPlayers;
//        fi.ignore();
//        FOR(i, 0, numPlayers - 1)
//        {
//            string s;
//            getline(fi, s);
//            FORd(j, s.size() - 1, 0)
//            {
//                if (s[j] == ' ')
//                {
//                    p[i].name = s.substr(0, j);
//                    p[i].points = stod(s.substr(j + 1, s.size() - j));
//                    break;
//                }
//            }
//        }
//    }
//}
//
//void Leader::WriteLeaderboardInfo()
//{
//    ofstream fo("info.txt");
//    fo << numPlayers << '\n';
//    FOR(i, 0, numPlayers - 1) {
//        fo << p[i].name << " " << p[i].points << '\n';
//    }
//}
