using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

//category represents the type of gadget
namespace UsedGadgetsSale.Models
{
    public class Category
    { //data annotations: validates user input
        [ScaffoldColumn(false)]
        public int CategoryID { get; set; }
        //data annotations: user input required
        [Required, StringLength(100), Display(Name = "Name")]
        public string CategoryName { get; set; }

        [Display(Name = "Gadget Description")]
        public string Description { get; set; }

        public virtual ICollection<Gadget> Gadgets { get; set; }
    }
}

