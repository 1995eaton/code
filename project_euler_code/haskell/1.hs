main = print $ sum[n | n<-[1..999], elem 0 [(mod) n 3, (mod) n 5]]
