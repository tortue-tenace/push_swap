GESTION D'ERREURS (3/4 minimum)
./push_swap a b c          → "Error\n" sur stderr  ✅
./push_swap 1 2 1          → "Error\n" sur stderr  ✅
./push_swap 1 2147483648   → "Error\n" sur stderr  ✅
./push_swap                → rien, prompt revient  ✅

ENTRÉES DÉJÀ TRIÉES (3/4 minimum)
./push_swap 42             → aucune sortie          ✅
./push_swap 2 3            → aucune sortie          ✅
./push_swap 0 1 2 3        → aucune sortie          ✅
./push_swap 0 1 2 3 4 5 6 7 8 9 → aucune sortie    ✅

SÉLECTION DE STRATÉGIE (3/5 minimum)
./push_swap --simple 5 4 3 2 1   → output valide   ✅
./push_swap --medium 5 4 3 2 1   → output valide   ✅
./push_swap --complex 5 4 3 2 1  → output valide   ✅ // ca affiche 101 a la fin, doit il yavoir un printf a suppr
./push_swap --adaptive 5 4 3 2 1 → output valide   ✅
./push_swap 5 4 3 2 1            → défaut adaptive ✅

3 NOMBRES (checker)
ARG="2 1 0"; ./push_swap $ARG | ./checker_linux $ARG → OK, ≤5 ops (≤3 excellent)  ✅/❌
ARG="0 2 1"; ./push_swap $ARG | ./checker_linux $ARG → OK, ≤5 ops                 ✅/❌
ARG="1 0 2"; ./push_swap $ARG | ./checker_linux $ARG → OK, ≤5 ops                 ✅/❌

5 NOMBRES (checker)
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_linux $ARG → OK, ≤15 ops (≤12 bon)  ✅/❌
ARG="5 1 4 2 3"; ./push_swap $ARG | ./checker_linux $ARG → OK, ≤15 ops            ✅/❌
ARG="3 5 1 4 2"; ./push_swap $ARG | ./checker_linux $ARG → OK, ≤15 ops            ✅/❌

50 NOMBRES (checker)
ARG=$(shuf -i 1-200 -n 50); ./push_swap --simple $ARG | ./checker_linux $ARG   → OK ✅/❌
ARG=$(shuf -i 1-200 -n 50); ./push_swap --medium $ARG | ./checker_linux $ARG   → OK ✅/❌
ARG=$(shuf -i 1-200 -n 50); ./push_swap --complex $ARG | ./checker_linux $ARG  → OK ✅/❌
ARG=$(shuf -i 1-200 -n 50); ./push_swap --adaptive $ARG | ./checker_linux $ARG → OK ✅/❌
--complex devrait utiliser moins d'ops que --simple                                  ✅/❌

100 NOMBRES (checker, 2-3 fois)
ARG=$(shuf -i 1-500 -n 100); ./push_swap $ARG | ./checker_linux $ARG → OK          ✅/❌
ARG=$(shuf -i 1-500 -n 100); ./push_swap $ARG | ./checker_linux $ARG → OK          ✅/❌
ARG=$(shuf -i 1-500 -n 100); ./push_swap $ARG | ./checker_linux $ARG → OK          ✅/❌
ops < 2000 (pass) / < 1500 (bon) / < 700 (excellent)                                ✅/❌

BENCHMARK
./push_swap --bench --simple 5 4 3 2 1 2>/dev/null             → ops sur stdout     ✅/❌
./push_swap --bench --simple 5 4 3 2 1 2>bench.txt >/dev/null && cat bench.txt      ✅/❌
  → disorder %                                                                       ✅/❌
  → nom stratégie + complexité                                                       ✅/❌
  → total ops                                                                        ✅/❌
  → compte par type d'opération                                                      ✅/❌
./push_swap --bench 1 2 3 4 5   → disorder ≈ 0.00%                                  ✅/❌
./push_swap --bench 5 4 3 2 1   → disorder ≈ 100.00%                                ✅/❌