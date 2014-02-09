for a in (1..1000)
  for b in (a+1..1000)
    if (a*a+b*b)**0.5 + b + a == 1000
      puts a * b * (a*a+b*b)**0.5
      exit
    end
  end
end
