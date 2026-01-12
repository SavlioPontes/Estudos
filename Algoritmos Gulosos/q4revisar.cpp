int multas(int n, int P[], int M[]) {

    // 1) ordenar por multa decrescente (insertion sort)
    for (int i = 1; i < n; i++) {
        int k = i;
        int j = i - 1;
        while (j >= 0 && M[k] > M[j]) {
            swap(M[k], M[j]);
            swap(P[k], P[j]);
            k = j;
            j--;
        }
    }

    // 2) vetor de dias
    bool ocupado[n + 1];
    for (int i = 1; i <= n; i++)
        ocupado[i] = false;

    int multaTotal = 0;

    // 3) alocação gulosa
    for (int i = 0; i < n; i++) {
        bool alocou = false;
        for (int d = P[i]; d >= 1; d--) {
            if (!ocupado[d]) {
                ocupado[d] = true;
                alocou = true;
                break;
            }
        }
        if (!alocou)
            multaTotal += M[i];
    }

    return multaTotal;
}
