FNR>8 && $4 !~ /Total/ {
    hours = $3
    domain = $4
    task = $5

    gsub(/[[:space:]]+/, "", domain)

    total += hours
    domains[domain] += hours
}

END {
    printf "Bereiche:\n"
    for (domain in domains) {
        printf "%20s: %10.1f Stunden\n", domain, domains[domain]
    }
    printf "%20s: %10.1f Stunden\n", "Total", total
}
