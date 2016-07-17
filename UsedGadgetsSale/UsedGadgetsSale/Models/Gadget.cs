using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;
/*This project is being done using the template of Microsoft's tutorial
  for web forms. Reference: http://www.asp.net/web-forms/overview/getting-started/getting-started-with-aspnet-45-web-forms/introduction-and-overview

 */
 //each instance of gadget class will represent a row in Relational DB.
namespace    UsedGadgetsSale.Models
{
    public class Gadget
    {
        [ScaffoldColumn(false)]
        public int GadgetID { get; set; }

        [Required, StringLength(100), Display(Name ="Name")]
        public string GadgetName { get; set; }

        [Required, StringLength(1000), Display(Name ="Gadget Description"), DataType(DataType.MultilineText)]
        public string Description { get; set; }

        public string ImagePath { get; set; }

        [Display(Name = "Price")]
        public double? UnitPrice { get; set; }

        public int? CategoryID { get; set; }

        public virtual Category Category { get; set; }


    }
}