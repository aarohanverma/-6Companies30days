class Solution {
public:
    bool winnerOfGame(string colors) {
        int As = 0, Bs = 0;
        
        for(int i = 0; i < colors.size() - 1; i++)
        {
            int cnt = 1;
            char curr = colors[i];
            while(i < colors.size() - 1 && colors[i] == colors[i + 1])
            {
                cnt++;
                i++;
            }
            if(cnt >= 3)
            {
                if(curr == 'A')
                {
                    As += (cnt - 2);
                }
                else
                {
                    Bs += (cnt - 2);
                }
            }
        }
        return As > Bs;
    }
};
