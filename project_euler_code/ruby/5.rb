(670442572800..670442572800).each { |n| puts n if (2..20).each { |a| n /= a while (2..20).all? { |b| (n/a).to_i % b == 0 } } }
