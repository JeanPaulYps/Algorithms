#include <bits/stdc++.h>

using namespace std;

struct dimension
{
    int lower_bound;
    int upper_bound;
};


struct arr
{
    string name;
    int base_address;
    int size;
    int number_dimensions;
    vector <dimension> dimensions;
    vector <int> constants;
};

void calculate_constants(arr &a)
{
    //cout << constants.size() << "\n";
    a.constants.resize(a.number_dimensions  + 1, 0);
    a.constants[a.number_dimensions] = a.size;
    for (int i = a.number_dimensions - 1; i > 0; i--)
    {
        a.constants[i] = a.constants[i + 1] * (a.dimensions[i].upper_bound - a.dimensions[i].lower_bound + 1);
    }
    int acu = a.base_address;
    for(int i = 1; i < a.number_dimensions + 1; i++)
    {
        acu -= a.constants[i] * a.dimensions[i - 1].lower_bound;
    }
    a.constants[0] = acu;

    /*for (auto &x: constants)
        cout << x << " ";
    cout << "\n";*/
}

void set_arr (string n, int b_a, int s, int n_d, vector <dimension> d, arr &a)
{
    a.name = n;
    a.base_address = b_a;
    a.size = s;
    a.number_dimensions = n_d;
    a.dimensions = d;
    calculate_constants(a);
}

int calculate_reference(vector <int> &indices, arr &a)
{
    int reference = a.constants[0];
    for (int i = 0; i < a.number_dimensions; i++)
    {
        /*cout << "indices " << indices[i] << "\n";
        cout << "constant " << a.constants[i+1] << "\n";*/

        reference += indices[i] * a.constants[i+1];
    }
    return reference;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    /*arr a[1];
    vector <dimension> dimensions = {{0, 3}, {1, 5}};
    vector <int> indices = {2,4};
    int number_dimensions = 2, size = 2, base_address = 1500;
    string name = "ONE";
    set_arr (name, base_address, size, number_dimensions, dimensions, a[0]);
    cout << calculate_reference(indices, a[0]) << "\n";*/

    int N, R, con = 0;
    cin >> N >> R;
    unordered_map <string, int> string_to_index;
    arr arrays[N];
    while (N--)
    {
        int base_address, size, number_dimensions, lower_bound, upper_bound;
        string name;
        vector <dimension> dimensions;

        cin >> name >> base_address >> size >> number_dimensions;

        for (int i = 0; i < number_dimensions; i++)
        {
            cin >> lower_bound >> upper_bound;

            dimensions.push_back(dimension{lower_bound, upper_bound} );
        }
        //vector <dimension> dimensions = {dimension(0, 3), dimension(1, 5)};
        set_arr(name, base_address, size, number_dimensions, dimensions, arrays[con]);
        string_to_index[name] = con;
        con ++;
        
    }
    
    while(R--)
    {
        int index;
        string name;
        vector <int> indices;
        cin >> name;
        for (int i = 0; i < arrays[string_to_index[name]].number_dimensions; i++)
        {
            cin >> index;
            indices.push_back(index);
        }
        cout << name << "[" << indices[0];
        for (int i = 1; i < arrays[string_to_index[name]].number_dimensions; i++)
            cout << ", " << indices[i];
        cout << "] = " << calculate_reference(indices, arrays[string_to_index[name]]) << "\n";
        //cout << calculate_reference(indices, arrays[string_to_index[name]]) << "\n";
    }  
    
}