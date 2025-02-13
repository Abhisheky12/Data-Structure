 

   //FIRST APPROCH IS ON GFG

class Solution
{
    public:
    // Function to perform case-specific sorting of strings.
    string sort(string str, int n){
        vector<int> lower(26, 0);  // Count for lowercase letters
        vector<int> upper(26, 0);  // Count for uppercase letters
        string lowerchar, upperchar;

        // Count lowercase and uppercase letters and use placeholders
        for(int i = 0; i < n; i++){
            if(str[i] >= 'a' && str[i] <= 'z'){  // Lowercase
                lower[str[i] - 'a']++;
                str[i] = '#';  // Placeholder for lowercase
            }
            else if(str[i] >= 'A' && str[i] <= 'Z'){  // Uppercase
                upper[str[i] - 'A']++;
                str[i] = '*';  // Placeholder for uppercase
            }
        }

        // Generate sorted lowercase characters
        for(int i = 0; i < 26; i++){
            char c = 'a' + i;
            while(lower[i]){
                lowerchar += c;
                lower[i]--;
            }
        }

        // Generate sorted uppercase characters
        for(int i = 0; i < 26; i++){
            char c = 'A' + i;
            while(upper[i]){
                upperchar += c;
                upper[i]--;
            }
        }

        // Reinserting lowercase characters back into their original positions
        int lowerIndex = 0, upperIndex = 0;
        for(int i = 0; i < n; i++){
            if(str[i] == '#'){  // Lowercase placeholder
                str[i] = lowerchar[lowerIndex++];
            }
            else if(str[i] == '*'){  // Uppercase placeholder
                str[i] = upperchar[upperIndex++];
            }
        }

        return str;
    }

    string caseSort(string str, int n)
    {
        return sort(str, n);
    }
};
