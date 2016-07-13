using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace UsedGadgetsSale.Models
{
    public class Gadget
    {
        [ScaffoldColumn(false)]
        public int GadgetID { get; set; }

        [Required, StringLength(100), Display(Name ="Name")]
        public string GadgetName { get; set; }

        [Required, StringLength(100), Display(Name ="Gadet Description"), DataType(DataType.MultilineText)]
        public string Description { get; set; }
        

    }
}