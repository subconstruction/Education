    int tableSize = 10;

    for (int i = 2; i <= tableSize; ++i) {

        for (int j = 1; j <= 10; ++j) {
            int mResult = i * j;

            if (i == 2 && j == 2) iter = "2x2=" + to_string(mResult);
            cout << i << " x " << j << " = " << mResult << "\n";
        }

        cout << "\n";
    }

    cout << "My iteration: " << iter;