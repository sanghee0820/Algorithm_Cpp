
        cout << func << "\n";
        int solution = 0;
        for(int i = 0; i < N; i++){
            switch(func[2*i + 1]){
                case('<'):{
                    if(func[2*i] < func[2*i + 2]){
                        solution += pow(10,N - i) * (func[2*i] - 48);
                        break;
                    }
                    else{
                        return;
                    }
                }
                case('>'):{
                    if(func[2*i] > func[2*i + 2]){
                        solution += pow(10,N - i) * (func[2*i] - 48);
                        break;
                    }