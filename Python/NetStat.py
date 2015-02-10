import sys
import math

def fit( counts, total, prompt ):
    summ = 0;
    maxC = 0;
    
    total_so_far = 0.0;

    for c in sorted(counts.iterkeys()):
        total_so_far = total_so_far + counts[c];

        print str(c) + " : " + str(counts[c]),
        if (total > 0):
            print " ( " + str("%.2f" % (total_so_far / total)) + "% )"
        else:
            print ""
        maxC = c;
        summ = summ + math.log(counts[c]);
       
    a = 1. + (maxC / summ);
        
    print str(prompt) + " : " + str( a )
    print str(prompt) + " Err : " + str((a - 1) / math.sqrt(maxC))
